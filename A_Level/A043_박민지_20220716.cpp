/*
Source: https://leetcode.com/problems/longest-common-prefix/

Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string output = "";
		char comp;
        int j;
        for(int i=0; i<strs[0].size(); i++){
			comp = strs[0][i];
			for(j=1; j<strs.size(); j++){
				if(comp != strs[j][i]){
					break;
				}
			}
			if(j == strs.size()) output = output + comp;
			else break;
		}
		return output;
    }
};