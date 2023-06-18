/*
        2328. Number of Increasing Paths in a Grid


        You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.


Example 1:

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.


Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.



Constraints:


        m == grid.length
        n == grid[i].length
        1 <= m, n <= 1000
        1 <= m * n <= 105
        1 <= grid[i][j] <= 105
        */

#include <bits/stdc++.h>
using namespace std;
static int MOD = 1e9 + 7;
static vector<int> dirs = {0, 1, 0, -1, 0};
class Solution
{
public:
        vector<vector<long>> memo;
        long dp(vector<vector<int>> &grid, int i, int j)
        {
                long result = 1;      // Contribution of current cell as an increasing sequence.
                if (memo[i][j] != -1) // Return the cached results if they exist.
                        return memo[i][j];
                for (int d = 0; d < 4; d++)
                { // Check all 4 directions.
                        int x = i + dirs[d], y = j + dirs[d + 1];
                        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] > grid[i][j])
                                result = (result + dp(grid, x, y)) % MOD; // Add the total number of cells in the longest path for all directions.
                }
                return memo[i][j] = result;
        }
        int countPaths(vector<vector<int>> &grid)
        {
                long result = 0;
                memo.resize(grid.size(), vector<long>(grid[0].size(), -1));
                for (int i = 0; i < grid.size(); i++) // For each cell as a starting point calculate the number of increasing paths it can contribute.
                        for (int j = 0; j < grid[0].size(); j++)
                                result = (result + dp(grid, i, j)) % MOD;
                return result;
        }
};