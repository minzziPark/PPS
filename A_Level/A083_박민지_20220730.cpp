/*
Source: https://www.acmicpc.net/problem/10867

중복 빼고 정렬하기

문제
N개의 정수가 주어진다. 이때, N개의 정수를 오름차순으로 정렬하는 프로그램을 작성하시오. 같은 정수는 한 번만 출력한다.

입력
첫째 줄에 수의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 수를 오름차순으로 정렬한 결과를 출력한다. 이때, 같은 수는 한 번만 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, num;
	cin >> N;
	vector<int> v;

	for(int i=0; i<N; i++){
		cin >> num;
		auto it = find(v.begin(), v.end(), num);
		if(it == v.end()){
			v.push_back(num);
		}
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	return 0;
}