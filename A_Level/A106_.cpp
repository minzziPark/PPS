/*
Source: https://www.acmicpc.net/problem/3059

등장하지 않는 문자의 합

문제
알파벳 대문자로 구성되어있는 문자열 S가 주어졌을 때, S에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 구하는 프로그램을 작성하시오.

문자열 S가 “ABCDEFGHIJKLMNOPQRSTUVW” 일 때, S에 등장하지 않는 알파벳 대문자는 X, Y, Z이다. X의 아스키 코드 값은 88, Y는 89, Z는 90이므로 이 아스키 코드 값의 합은 267이다.

알파벳 대문자의 아스키 코드 값은 다음과 같다.

입력
입력은 T개의 테스트 데이터로 구성된다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터는 한 줄로 구성되어 있고, 문자열 S가 주어진다. S는 알파벳 대문자로만 구성되어 있고, 최대 1000글자이다.

출력
각 테스트 데이터에 대해, 입력으로 주어진 문자열 S에 등장하지 않는 알파벳 대문자의 아스키 코드 값의 합을 한 줄에 하나씩 출력한다.
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	string str;
	
	int alpha = 65;
	int result = 0;
	cin.ignore();
	
	for(int i=0; i<T; i++){
		alpha = 65;
		result = 0;
		
		getline(cin, str, '\n');

		sort(str.begin(), str.end());

		for(int i=0; i<str.size(); i++){
			if(i == 0 || str[i-1] != str[i]){
				while(int(str[i]) != alpha){
					cout << int(str[i]) << endl;
					if(alpha == 91){
						break;
					}
					result += alpha;
					alpha++;
				}
				if(int(str[i]) == alpha){
					alpha++;
				}
			}
		}
		
		while(alpha < 91){
			result += alpha;
			alpha++;
		}
		cout << result << '\n';
	}
	return 0;
}