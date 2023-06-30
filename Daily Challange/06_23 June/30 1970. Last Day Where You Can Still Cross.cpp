/*
        1970. Last Day Where You Can Still Cross
        

        There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 
Example 1:

Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.


Example 2:

Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.


Example 3:

Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.


 
Constraints:


	2 <= row, col <= 2 * 104
	4 <= row * col <= 2 * 104
	cells.length == row * col
	1 <= ri <= row
	1 <= ci <= col
	All the values of cells are unique.
        */
        

        #include <bits/stdc++.h>
        using namespace std;
class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid; // Update current answer so far
                left = mid + 1; // Try to find a larger day
            } else right = mid - 1; // Try to find a smaller day
        }
        return ans;
    }
    int DIR[5] = {0, 1, 0, -1, 0};
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
        vector<vector<bool>> grid(row, vector<bool>(col, 0)); // Create grid in the `dayAt` th date
        for (int i = 0; i < dayAt; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int, int>> bfs;
        for (int c = 0; c < col; ++c) {
            if (grid[0][c] == 0) { // Add all valid start cells in the top row
                bfs.push({0, c});
                grid[0][c] = 1; // Mark as visited
            }
        }
        while (!bfs.empty()) {
            auto [r, c] = bfs.front(); bfs.pop();
            if (r == row - 1) return true; // Reach to bottom -> Return Valid
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1; // Mark as visited
                bfs.push({nr, nc});
            }
        }
        return false;
    }
};