/*
Source: https://docs.google.com/spreadsheets/d/1wp9H03-EOUUiXt0PvDMDZwu8gy0LM-cvYa1YK2e3IEk/edit#gid=1988099618
숫자놀이

문제
79를 영어로 읽되 숫자 단위로 하나씩 읽는다면 "seven nine"이 된다. 80은 마찬가지로 "eight zero"라고 읽는다. 79는 80보다 작지만, 영어로 숫자 하나씩 읽는다면 "eight zero"가 "seven nine"보다 사전순으로 먼저 온다.

문제는 정수 M, N(1 ≤ M ≤ N ≤ 99)이 주어지면 M 이상 N 이하의 정수를 숫자 하나씩 읽었을 때를 기준으로 사전순으로 정렬하여 출력하는 것이다.

입력
첫째 줄에 M과 N이 주어진다.

출력
M 이상 N 이하의 정수를 문제 조건에 맞게 정렬하여 한 줄에 10개씩 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	string alpha[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	vector<pair<string, int>> vec;
	string str = ""; 

	for(int i=a; i<=b; i++){
		int temp = i;

		if(temp >= 10){
			while(temp != 0){
				str = alpha[temp%10] + str;
				temp /= 10;
			}
		}else{
			str = alpha[temp];
		}
		vec.push_back(pair<string, int>(str, i));
	}
	sort(vec.begin(), vec.end());

	for(int i=0; i<vec.size(); i++){
		if(i != 0 && i%10 == 0) cout << "\n";
		cout << vec[i].second << " ";
	}
	return 0;
}