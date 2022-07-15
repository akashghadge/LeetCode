/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//     int util(vector<vector<int>> & grid,vector<vector<bool>> & visit,int i,int j,int *maxArea,int curr)
//     {
//         if(*maxArea<curr)
//         {
//             *maxArea=curr;
//         }
//         if(i==grid.size() || i<0 || j<0 || j==grid[0].size())
//         {
//             return 0;
//         }
//         if(visit[i][j]==true || grid[i][j]==0)
//         {
//             if(j==grid[0].size()-1)
//             {
//                 i++;
//             }
//             else
//             {
//                 j++;
//             }   
//             util(grid,visit,i,j,maxArea,curr);
//         }
        
//         util(grid,visit,i-1,j,maxArea,curr);
//         util(grid,visit,i,j+1,maxArea,curr);
//         util(grid,visit,i+1,j,maxArea,curr);
//         util(grid,visit,i,j-1,maxArea,curr);
        
//         return 0;
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         vector<vector<bool>> visit(grid.size(),vector<bool> (grid[0].size(),false));  
//         if(grid.size()==0)
//         {
//             return 0;
//         }
//         int maxArea=0;
//         util(grid,visit,0,0,&maxArea,0);
//         return maxArea;
//     }
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // right, left, up and down
    
    void dfs(int position, vector<vector<int>> &grid, unordered_set<int> &visited, size_t numRow, size_t numCol, int &area)
    {
        int row = position / numCol;
        int col = position % numCol;
        
        if (grid[row][col] == 1 && !visited.count(position))
        {
            visited.insert(position);
            area++;
            for (int i = 0; i < 4; i++)
            {
                int r = row + directions[i][0];
                int c = col + directions[i][1];
                int pos = r * numCol + c;
                if (r < 0 || c < 0 || r >= numRow || c >= numCol || visited.count(pos) || grid[r][c] == 0)
                {
                    continue;
                }
                dfs(pos, grid, visited, numRow, numCol, area);
            }
        }
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        size_t numRow = grid.size();
        size_t numCol = grid[0].size();
        
        int max = 0;
        int area = 0;
        unordered_set<int> visited;
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                int position = i * numCol + j;
                if (grid[i][j] == 1 && !visited.count(position))
                {
                    area = 0;
                    dfs(position, grid, visited, numRow, numCol, area);
                    if (max < area)
                    {
                        max = area;
                    }
                }
            }
        }
        
        return max;
    }
};
int main()
{
}