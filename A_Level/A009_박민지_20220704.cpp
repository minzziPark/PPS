/*
Source: https://school.programmers.co.kr/learn/courses/30/lessons/12918

# 문제 설명
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 
예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.

# 제한 사항
s는 길이 1 이상, 길이 8 이하인 문자열입니다.

# 입출력 예
s	    return
"a234"	false
"1234"	true
*/
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
	int i;

	if(s.length() == 4 || s.length() == 6){
		for(i = 0; i<s.length(); i++){
			if(isdigit(s[i]) == 0) {
				answer = false;
				break;
			}
		}
		if(i == s.length()) answer = true;
	}else answer = false;

    return answer;
}