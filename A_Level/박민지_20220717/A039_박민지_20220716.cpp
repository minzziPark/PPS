/*
Source: https://leetcode.com/problems/valid-perfect-square/

367. Valid Perfect Square

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        double s=0;
		double t=0;
		int result_int;
		bool result = true;

		s = num/2;
		for(;s != t;){
			t = s;
			s = ((num/t) + t) /2;
		}
		result_int = (int)s;
		
		if(s != result_int && num != 1){
			result = false;
		}
		return result;
    }
};