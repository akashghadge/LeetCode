/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.



Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1


Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int sz = board.size();
        int target = sz * sz;
        unordered_map<int, int> moves;
        moves[1] = 0; // Zero(No) moves when we are in square 1
        queue<int> q;
        q.push(1); // BFS method

        while (!q.empty())
        {
            int current_sq = q.front();
            q.pop();

            for (int i = 1; i <= 6; i++)
            {
                int next_sq = current_sq + i;
                if (next_sq > target)
                {
                    break;
                }

                int row = (next_sq - 1) / sz;
                int col = (row % 2 == 0) ? (next_sq - 1) % sz : sz - 1 - ((next_sq - 1) % sz);

                if (board[sz - 1 - row][col] != -1)
                {
                    next_sq = board[sz - 1 - row][col];
                }
                if (moves.count(next_sq) == 0)
                {
                    moves[next_sq] = moves[current_sq] + 1;
                    if (next_sq == target)
                    {
                        return moves[next_sq];
                    }
                    q.push(next_sq);
                }
            }
        }

        return -1;
    }
};
int main()
{
}