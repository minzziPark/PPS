/*
Source: https://leetcode.com/problems/add-binary/

67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int l_idx = a.size()-1, s_idx = b.size()-1;
		string l_str = a, s_str = b;
		bool next = false;
		string answer = "";

		if(a.size() < b.size()) {
			l_idx = b.size()-1;
			s_idx = a.size()-1;
			l_str = b;
			s_str = a;
		}

		for(int i=l_idx; i>=0 ; i--){
			if(s_idx >= 0){
				if(s_str[s_idx] == '1' && l_str[i] == '1'){
					if(next) answer = "1" + answer;
					else answer = "0" + answer;
					next = true;
				}else if(s_str[s_idx] == '0' && l_str[i] == '0'){
					if(next){
						answer = "1" + answer;
						next = false;
					}else{
						answer = "0" + answer;
					}
				}else{
					if(next){
						answer = "0" + answer;
						next = true;
					}else{
						answer = "1" + answer;
					}
				}
			}else{
                if(next){
                    if(l_str[i] == '1'){
                        answer = "0" + answer;
						next = true;
                    }else{
                        answer = "1" + answer;
                        next = false;
                    }
                }else{
                    string s;
                    s += l_str[i];
                    answer = s + answer;
                }
			}
            s_idx--;
		}
		if(next) answer = "1" + answer;

		return answer;
    }
};