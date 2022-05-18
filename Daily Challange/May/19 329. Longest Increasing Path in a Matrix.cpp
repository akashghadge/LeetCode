/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
int DFS(vector<vector<int>> &matrix, int i, int j, int val, vector<vector<int>> &dp)
{
int n = matrix.size(), m = matrix[0].size();

    if(i < 0 || i == n || j < 0 || j == m || matrix[i][j] <= val)
        return 0;
    
    if(dp[i][j] != 0) // if path already searched
        return dp[i][j];
        
    int a = DFS(matrix, i+1, j, matrix[i][j], dp) + 1;
    int b = DFS(matrix, i-1, j, matrix[i][j], dp) + 1;
    int c = DFS(matrix, i, j+1, matrix[i][j], dp) + 1;
    int d = DFS(matrix, i, j-1, matrix[i][j], dp) + 1;
        
    dp[i][j] = max(a, max(b, max(c,d)));
    return dp[i][j];
    
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    
    int ans=0,n = matrix.size(), m = matrix[0].size();
    
    vector<int> temp(m, 0);
    vector<vector<int>> dp(n, temp); // Initializating 2D vector with size [n][m] all values with zero

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans = max(ans, DFS(matrix, i, j, INT_MIN, dp));
        }
    }
    return ans;
}
};
int main()
{
}