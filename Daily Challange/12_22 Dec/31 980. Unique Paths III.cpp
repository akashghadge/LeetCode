/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example 1:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:


Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
1 <= m * n <= 20
-1 <= grid[i][j] <= 2
There is exactly one starting cell and one ending cell.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool valid(vector<vector<int>> &arr, vector<vector<int>> &visited, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && arr[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    void help(vector<vector<int>> &arr, vector<vector<int>> visited,
              int n, int m, int r, int c, int *ans)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || visited[r][c] || arr[r][c] == -1)
        {
            return;
        }
        visited[r][c] = true;
        if (arr[r][c] == 2)
        {
            if (valid(arr, visited, n, m))
            {
                *ans = *ans + 1;
            }
            return;
        }
        help(arr, visited, n, m, r + 1, c, ans);
        help(arr, visited, n, m, r, c + 1, ans);
        help(arr, visited, n, m, r - 1, c, ans);
        help(arr, visited, n, m, r, c - 1, ans);
        visited[r][c] = false;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int r = 0;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    r = i;
                    c = j;
                }
            }
        }
        int ans = 0;
        help(grid, visited, n, m, r, c, &ans);
        return ans;
    }
};
int main()
{
}