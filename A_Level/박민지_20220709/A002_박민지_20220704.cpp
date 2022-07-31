/*
Source: https://leetcode.com/problems/pascals-triangle/

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#############################

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Input: numRows = 1
Output: [[1]]

#############################
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
		int numCols = 1;
		int sum = 0;
		if(numRows == 0){
			return output;
		}

		for(int i=0; i<numRows; i++){
			vector<int> addRow;
			
			for(int j=0; j<numCols; j++){
				if(j == 0 || j == numCols-1){
					addRow.push_back(1);
					if(i == 0) output.push_back(addRow);
				}else{
					sum = output[i-1][j-1] + output[i-1][j];
					addRow.push_back(sum);
				}
			}
			if(i != 0) output.push_back(addRow);
			numCols++;
		}
		return output;
    }
};