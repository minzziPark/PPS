/*
Source: https://leetcode.com/problems/plus-one/

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

####################################
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
####################################
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> output = digits;
		int lastNum = 0;
		int idx = output.size()-1;

		lastNum = output[idx] +1;
		output[idx] = lastNum;

		while(idx != -1 && lastNum == 10){
            if(idx != 0){
                lastNum = output[idx-1] + 1;
			    output[idx-1] = lastNum;
                output[idx] = 0;
            }else{
                if(output[idx] == 10){
                    output[idx] = 0;
                    output.insert(output.begin(), 1);
                }
            }
            idx--;
		}

		return output;
    }
};