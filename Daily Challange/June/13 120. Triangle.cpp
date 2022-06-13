/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(2,vector<int>(n,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                if(i==n-1)
                {
                    dp[0][j]=arr[i][j];
                }
                else
                {
                    dp[0][j]=arr[i][j]+min(dp[1][j],dp[1][j+1]);
                }
            }
            dp[1]=dp[0];
        }
        return dp[1][0];
    }
};
int main()
{
}