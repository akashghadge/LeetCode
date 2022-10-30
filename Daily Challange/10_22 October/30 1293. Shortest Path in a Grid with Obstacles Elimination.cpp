/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:


Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
Example 2:


Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 40
1 <= k <= m * n
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> a = {-1,0,1,0};
    vector<int> b = {0,-1,0,1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        queue<array<int,3>> q;
        int ans = 0;
        
        q.push({0,0,k}); // initially we can remove k obstacles
        
        map<pair<int,int>, int> vis; // map coordinates to the number of moves remaining
        vis[{0,0}] = k;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; ++i) {
                auto it = q.front(); q.pop();
                int x = it[0];
                int y = it[1];
                int canRemove = it[2];
                
                if(x == m-1 && y == n-1) return ans;
                
                for(int k=0; k<4; ++k) {
                    int dx = x + a[k];
                    int dy = y + b[k];
                    
                    if(dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                    
                    int remaining = canRemove - grid[dx][dy];
                    
                    if(remaining >= 0 && (vis.find({dx,dy}) == vis.end() || vis[{dx,dy}] < remaining)) {
                        vis[{dx,dy}] = remaining;
                        q.push({dx,dy, remaining});
                    }
                }
                
            }
            ++ans;
        }
        
        return -1;
    }
};
int main()
{
}