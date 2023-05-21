/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.



Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1


Constraints:

n == grid.length == grid[i].length
2 <= n <= 100
grid[i][j] is either 0 or 1.
There are exactly two islands in grid.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        markGridTwo(grid);

        for (int color = 2;; ++color)
            for (int i = 0; i < grid.size(); ++i)
                for (int j = 0; j < grid[0].size(); ++j)
                    if (grid[i][j] == color)
                        if (expand(grid, i + 1, j, color) || //
                            expand(grid, i - 1, j, color) || //
                            expand(grid, i, j + 1, color) || //
                            expand(grid, i, j - 1, color))
                            return color - 2;
    }

private:
    // Marks one group to 2s by DFS.
    void markGridTwo(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                {
                    markGridTwo(grid, i, j);
                    return;
                }
    }

    void markGridTwo(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return;
        if (grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        markGridTwo(grid, i + 1, j);
        markGridTwo(grid, i - 1, j);
        markGridTwo(grid, i, j + 1);
        markGridTwo(grid, i, j - 1);
    }

    // Returns true if we touch 1s' group through expanding.
    bool expand(vector<vector<int>> &grid, int i, int j, int color)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return false;
        if (grid[i][j] == 0)
            grid[i][j] = color + 1;
        return grid[i][j] == 1;
    }
};

int main()
{
}