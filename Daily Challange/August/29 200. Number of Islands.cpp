/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int n,int m,vector<vector<int>>&vis)
    {
        if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || grid[r][c]=='0')
            return;
        vis[r][c]=true;
        dfs(grid,r+1,c,n,m,vis);
        dfs(grid,r-1,c,n,m,vis);
        dfs(grid,r,c-1,n,m,vis);
        dfs(grid,r,c+1,n,m,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {   
                    dfs(grid,i,j,n,m,vis);
                    c++;
                }
            }
        }
        return c;
    }
};
int main()
{
}