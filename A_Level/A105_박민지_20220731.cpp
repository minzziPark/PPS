/*
Source: https://www.acmicpc.net/problem/1193

분수찾기

이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.

X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.

출력
첫째 줄에 분수를 출력한다.

*/
#include <iostream>

using namespace std;

int main(){
	int num = 0;
	int add = 0;
	int get;
	int low = 1, high;
	cin >> get;

	while(num < get){
		add++;
		num += add;
	}
	num -= add;
	num++;
	
	if(add%2 == 0){
		high = 1;
		low = add;
		while(get != 1 && num < get){
			low--;
			high++;
			num++;
		}
	}else{
		high = add;
		low = 1;
		while(get != 1 && num < get){
			low++;
			high--;
			num++;
		}
	}
	
	

	cout << high << "/" << low << "\n";



	return 0;
}