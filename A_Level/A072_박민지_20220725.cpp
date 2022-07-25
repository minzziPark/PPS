/*
Source: https://leetcode.com/problems/day-of-the-year/

1154. Day of the Year

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
*/
class Solution {
public:
    int dayOfYear(string date) {
        int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int year = stoi(date.substr(0, 4));
		int mon = stoi(date.substr(5,2));
		int day = stoi(date.substr(8,2));

		int result = 0;

		if(year == 1900) month[2] = 28;
		else{
			if(year%4 == 0) month[2] = 29;
		}

		if(mon == 1){
			result += day;
		}else{
			for(int i=1; i<mon; i++){
				result += month[i];
			}
			result += day;
		}
		return result;
    }
};