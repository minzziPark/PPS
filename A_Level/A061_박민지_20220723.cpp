/*
Source: https://leetcode.com/problems/excel-sheet-column-title/

168. Excel Sheet Column Title

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
		string answer = "";
		
        while(columnNumber != 0){
            string s;
			if(columnNumber / 26 >= 26){
                if(columnNumber%26 == 0){
                    s += 90;
                    answer = s + answer;
                    columnNumber = columnNumber/26 -1;
                }else{
                    s += (columnNumber%26 +64);
                    answer = s + answer;
                    columnNumber /= 26;
                } 
                
            }else if(columnNumber / 26 < 26 && columnNumber / 26 > 0){
                if(columnNumber%26 == 0){
                    s += 90;
                    answer = s + answer;
                    s = "";
                    if(columnNumber/26 != 1){
                        s += (columnNumber/26 +63);
                        answer = s + answer;
                    }
                }else{
                    s += (columnNumber%26 +64);
                    answer = s + answer;
                    s = "";
                    s += (columnNumber/26 +64);
                    answer = s + answer;
                } 
                break;
            }else{
                if(columnNumber%26 == 0){
                    s += 90;
                }else s += (columnNumber%26 +64);
                answer = s + answer;
                break;
            }
		}
		return answer;
    }
};