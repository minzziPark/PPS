/*
Source: https://www.acmicpc.net/problem/3062

수 뒤집기

문제
수 124를 뒤집으면 421이 되고 이 두 수를 합하면 545가 된다. 124와 같이 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되는지 테스트 하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄에 하나의 정수 N(10 ≤ N ≤ 100000)이 주어진다.

출력
각 테스트 케이스에 대해서 원래 수와 뒤집은 수를 합한 수가 좌우 대칭이 되면 YES를 아니면 NO를 한 줄에 하나씩 출력한다.
*/
#include <iostream>

using namespace std;

int main(){
	int T;
	int num, temp;
	int back_num = 0;
	string num_str = "";
	string result = "YES";
	cin >> T;

	for(int i=0; i<T; i++){
		back_num = 0;
		result = "YES";
		num_str = "";
		cin >> num;
		temp = num;

		while(temp != 0){
			back_num = back_num*10 + temp%10;
			temp /= 10;
		}
		
		num += back_num;
		num_str = to_string(num);

		for(int j=0; j<num_str.size()/2; j++){
			if(num_str[j] != num_str[num_str.size()-1-j]) result = "NO";
		}
		
		cout << result << "\n";
	}
	return 0;
}