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

using namespace std;

int main(){
	unsigned long long a;
	unsigned long long b;

	cin >> a;
	cin >> b;

	cout << a+b << endl;

	return 0;
}