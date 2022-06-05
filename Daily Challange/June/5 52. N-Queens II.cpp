/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.



Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1


Constraints:

1 <= n <= 9

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalNQueens(int n)
    {
        vector<bool> col(n, true);
        vector<bool> anti(2 * n - 1, true);
        vector<bool> main(2 * n - 1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, main, anti, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool> &main, vector<bool> &anti, int &count)
    {
        if (i == row.size())
        {
            count++;
            return;
        }
        for (int j = 0; j < col.size(); j++)
        {
            if (col[j] && main[i + j] && anti[i + col.size() - 1 - j])
            {
                row[i] = j;
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = false;
                dfs(i + 1, row, col, main, anti, count);
                col[j] = main[i + j] = anti[i + col.size() - 1 - j] = true;
            }
        }
    }
};
int main()
{
}