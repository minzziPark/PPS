/*
Source: https://leetcode.com/problems/valid-palindrome/

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
		bool result = true;
		int last_idx = 0;
		string change_s = "";
        for(int i=0; i<s.size(); i++){
			if(isalpha(s[i]) || isdigit(s[i])){
				change_s += tolower(s[i]);
			}	
		}
		last_idx = change_s.size()-1;
		for(int i=0; i<change_s.size()/2; i++){
			if(change_s[i] == change_s[last_idx]){
				last_idx--;
			}else{
				result = false;
				break;
			}
		}

		return result;
    }
};
