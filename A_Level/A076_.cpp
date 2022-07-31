/*
Source: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG&categoryId=AWqU0zh6rssDFARG&categoryType=CODE&problemTitle=%EC%A0%95%EB%A0%AC&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1

[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 50)가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 이승 명부의 이름 개수 N(1 ≤ N ≤ 20,000)이 주어진다.

각 테스트 케이스의 두 번째 줄부터 N개의 줄에 걸쳐서 알파벳 소문자로 이루어진 이름들이 주어진다.

이름에는 공백이 포함되지 않으며 최소 1개, 최대 50개의 알파벳으로 이루어져 있다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

정리된 이름을 한 줄에 하나씩 출력하라. 같은 이름은 한 번만 출력해야 하는 것을 주의하라.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int T, N; 
	string get_name;

	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> N;
		string str[N];
		getline(cin, get_name);
		for(int j=0; j<N; j++){
			getline(cin, get_name);
			str[j] = get_name;
		}
		sort(str, str+N);
		cout << "#" << i+1 << "\n";
		for(int j=0; j<N; j++){
			if(j == 0 || str[j-1].compare(str[j]) != 0) cout << str[j] << "\n";
		}
	}

	return 0;
}