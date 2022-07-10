/*
Source: https://www.acmicpc.net/problem/10757

큰 수 A+B

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> a;
	vector<int> b;
	bool prev = false;
	int idx;
	int num_a, num_b, sum, size = 1;
	int ten = 1;

	string str_a;
	string str_b;

	cin >> str_a;
	cin >> str_b;
	if(str_a.size() > str_b.size()) idx = str_a.size();
	else idx = str_b.size();

	int result[idx+1];

	for(int i=0; i<str_a.size(); i++){
		a.push_back(str_a[i] - '0');
	}
	for(int i=0; i<str_b.size(); i++){
		b.push_back(str_b[i] - '0');
	}
	size = idx+1;

	for(int i=0; i<idx+1; i++){
		size--;
		if(!a.empty() && !b.empty()){
			num_a = a.back();
			num_b = b.back();
			sum = num_a + num_b;
			a.pop_back(); b.pop_back();
		}else if(a.empty() && !b.empty()){
			sum = b.back();
			b.pop_back();
		}else if(!a.empty() && b.empty()){
			sum = a.back();
			a.pop_back();
		}
		
		if(prev) sum++; 
		if(sum >= 10){
			sum = sum%10;
			prev = true;
		}else{
			prev = false;
		}
		result[size] = sum;
		num_a = 0;
		num_b = 0;

		sum = 0;
	}	

	prev = false;
	for(int i=0; i<idx+1; i++){
		if(!prev && result[i] == 0){
			continue;
		}else{
			prev = true;
			cout << result[i];
		}
	}

	return 0;
}