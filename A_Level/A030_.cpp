/*
Source: https://www.acmicpc.net/problem/17211

좋은 날 싫은 날

문제
지은이가 건국한 나라인 유애나에 살고 있는 재현이는 너무 단순한 나머지 매일이 기분이 좋은 날, 기분이 싫은 날 두가지로 나누어진다. 
어느 날 지은이는 재현이에 대한 놀라운 사실을 발견했다! 재현이의 오늘의 기분이 내일의 기분에 영향을 준다는 것이었다. 
문득 지은이는 N일 뒤의 재현이의 기분이 어떻게 될지 궁금하였다. 
지은이를 위해 N일 뒤 재현이의 기분이 어떨지 알려주는 프로그램을 만들어보자.

입력
첫째 줄에 정수 N(1 ≤ N ≤ 100)과 현재 재현이의 기분(좋은 날 0, 싫은 날 1)이 주어진다.

둘째 줄에 차례대로 재현이가 기분이 좋은 날의 다음 날도 기분이 좋은 날일 확률, 다음 날은 기분이 싫은 날일 확률, 기분이 싫은 날의 다음 날이 기분이 좋은 날일 확률, 다음 날도 기분이 싫은 날일 확률이 주어진다. 
확률은 소수점 둘째자리까지 주어진다.

출력
N일 뒤의 재현이의 기분이 좋은 날일 확률과 싫은 날일 확률에 1,000을 곱해 소수점 첫째자리에서 반올림한 수를 차례대로 출력한다. 
절대 오차는 100까지 허용한다.
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int N, mood, idx = 0, size = 0;
	float good = 0, bad = 0;
	float prob[4];
	cin >> N;
	cin >> mood;
	float *cal_A;
	float *cal_B;
	int A_size = 0;
	int B_size = 0;
 
	for(int i=0; i<4; i++){
		cin >> prob[i];
	}

	for(int i=0; i<N; i++){
		if(i == 0){
			size = 2;
			cal_A = new float[size];
			if(mood == 0){
				cal_A[0] = prob[0];
				cal_A[1] = prob[1];
			}else{
				cal_A[0] = prob[2];
				cal_A[1] = prob[3];
			}
			A_size = 2;
			continue;
		}
		size *= 2;
		if(A_size != 0){
			cal_B = new float[size];
			B_size = size;
			for(int j=0; j<(size/2); j++){
				if(j%2 == 0){
					cal_B[idx++] = cal_A[j]*prob[0];
					cal_B[idx++] = cal_A[j]*prob[1];
				}else{
					cal_B[idx++] = cal_A[j]*prob[2];
					cal_B[idx++] = cal_A[j]*prob[3];
				}
			}
			delete[] cal_A;
			A_size = 0;
			idx = 0;
		}else{
			cal_A = new float[size];
			A_size = size;
			for(int j=0; j<(size/2); j++){
				if(j%2 == 0){
					cal_A[idx++] = cal_B[j]*prob[0];
					cal_A[idx++] = cal_B[j]*prob[1];
				}else{
					cal_A[idx++] = cal_B[j]*prob[2];
					cal_A[idx++] = cal_B[j]*prob[3];
				}
			}
			delete[] cal_B;
			B_size = 0;
			idx = 0;
		}
	}

	if(A_size != 0){
		for(int i=0; i<A_size; i++){
			if(i%2 == 0){
				good += cal_A[i];
			}else{
				bad += cal_A[i];
			}
		}
		delete[] cal_A;
	}else{
		for(int i=0; i<B_size; i++){
			if(i%2 == 0){
				good += cal_B[i];
			}else{
				bad += cal_B[i];
			}
		}
		delete[] cal_B;
	}

	good *= 1000;
	bad *= 1000;

	cout << fixed;
	cout.precision(0);
	cout << good << endl;
	cout << bad << endl;

	return 0;
}

