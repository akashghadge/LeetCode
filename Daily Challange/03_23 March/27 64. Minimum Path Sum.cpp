/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> prev(m, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, INT_MAX);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 and j == 0)
                    curr[j] = arr[i][j];
                else
                {
                    int u = INT_MAX, l = INT_MAX;
                    if (i > 0)
                        u = prev[j];
                    if (j > 0)
                        l = curr[j - 1];
                    curr[j] = min(l, u) + arr[i][j];
                }
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};
int main()
{
}