/*
Source: https://leetcode.com/problems/single-number/

136. Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
*/
#include <vector>
#include <algorithm>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++){
            cout << nums[i] << " ";
        }
		int result = 1;
		int check = NULL;
        
        while(!nums.empty()){
            if(nums.back() == 1){
                nums.pop_back();
            }else{
                if(check == NULL){
                    check = nums.back();
				    nums.pop_back();
                    if(nums.empty()){
                        result = check;
                    }
                }else{
                    if(check == nums.back()){
                        nums.pop_back();
                        check = NULL;
                    }else{
                        result = check;
                        break;
                    }
                }
            } 
        }
        
        
		return result;
    }
};