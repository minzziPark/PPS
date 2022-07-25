/*
Source: https://www.codeground.org/practice/practiceProblemViewNew

시험공부

초등학생인 정우는 시험 기간을 맞아 공부를 시작해야 한다.

정우가 다니는 학교에선 총 N 개의 과목에 대해 시험을 보는데, 시간이 부족한 정우는 그 중 K 개의 과목만을 골라서 공부할 수 있다.
정우는 매우 특이한 학생이라서 어떤 과목을 공부한다면 그 과목에 대해선 무조건 같은 점수를 받게 된다고 한다.

정우는 시험 점수 총합을 최대화하기 위해 K 개의 과목을 골라야 한다.
하지만, 모든 과목을 공부할 시간이 없는 정우는, 당신에게 "최대 합계 점수"를 받을 수 있는 K개의 과목을 골라달라고 한다.
K개 과목을 골랐을 때 정우가 받을 수 있는 "최대 합계 점수"를 구하는 프로그램을 작성하라.
*/
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
	int N, K;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cin >> N;
		cin >> K;
		vector<int> score;
		int sr;
		Answer = 0;
		for(int i=0; i<N; i++){
			cin >> sr;
			score.push_back(sr);
		}
		sort(score.rbegin(), score.rend());

		for(int i=0; i<K; i++){
			Answer += score[i];
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}