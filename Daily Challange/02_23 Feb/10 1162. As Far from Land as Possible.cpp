/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.



Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        const vector<int> dirs{0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        int water = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    ++water;
                else
                    q.emplace(i, j);

        if (water == 0 || water == m * n)
            return -1;

        int ans = 0;

        for (int d = 0; !q.empty(); ++d)
            for (int sz = q.size(); sz > 0; --sz)
            {
                const auto [i, j] = q.front();
                q.pop();
                ans = d;
                for (int k = 0; k < 4; ++k)
                {
                    const int x = i + dirs[k];
                    const int y = j + dirs[k + 1];
                    if (x < 0 || x == m || y < 0 || y == n)
                        continue;
                    if (grid[x][y] > 0)
                        continue;
                    q.emplace(x, y);
                    grid[x][y] = 2; // Mark as visited.
                }
            }

        return ans;
    }
};

int main()
{
}