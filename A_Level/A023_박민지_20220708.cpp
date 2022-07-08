/*
Source: https://leetcode.com/problems/add-digits/

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:

	Input: num = 38
	Output: 2
	Explanation: The process is
	38 --> 3 + 8 --> 11
	11 --> 1 + 1 --> 2 
	Since 2 has only one digit, return it.

Example 2:

	Input: num = 0
	Output: 0
*/
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
		int digit = 0;
        
        while(num != 0){
            sum += (num%10);
            num /= 10;

			if(num == 0 && sum >= 10){
				num = sum;
				sum = 0;
			}
        }
        
        
        return sum;
    }
};
