/*
Source: https://leetcode.com/problems/count-primes/

204. Count Primes
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
*/
#include <vector>

class Solution {
public:
    int countPrimes(int n) {
		int result = 0;
		vector<int> a(n, 1);

		if(n < 2){
			return result;
		}
		for(int i=2; i<n; i++){
			if(a[i] == 1) {
				result++;
				for(int j=2*i; j<n; j+=i) a[j] = 0;
			}
		}
		return result;
    }
};



