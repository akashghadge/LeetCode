/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &A)
    {
        const int m = A.size();
        const int n = A[0].size();

        // Remove lands connected to edge
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i * j == 0 || i == m - 1 || j == n - 1)
                    if (A[i][j] == 1)
                        dfs(A, i, j);

        return accumulate(begin(A), end(A), 0, [](int s, vector<int> &row)
                          { return s + accumulate(begin(row), end(row), 0); });
    }

private:
    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i < 0 || i == A.size() || j < 0 || j == A[0].size())
            return;
        if (A[i][j] == 0)
            return;

        A[i][j] = 0;
        dfs(A, i + 1, j);
        dfs(A, i - 1, j);
        dfs(A, i, j + 1);
        dfs(A, i, j - 1);
    };
};

int main()
{
}