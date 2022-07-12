/*
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
 

Constraints:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108
Accepted
126,685
Submissions
310,934

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& M) {
        sort(M.begin(), M.end(), greater<int>());
        int total = accumulate(M.begin(), M.end(), 0);
        side = total / 4;
        if ((float)total / 4 > side || M[0] > side)
            return false;
        return btrack(0, side, 0, M);
    }
private:
    int side;
    bool btrack(int i, int space, int done, vector<int>& M) {
        if (done == 3)
            return true;
        for (; i < M.size(); i++) {
            int num = M[i];
            bool res;
            if (num > space)
                continue;
            M[i] = side + 1;
            if (num == space)
                res = btrack(1, side, done+1, M);
            else
                res = btrack(i+1, space-num, done, M);
            if (res)
                return true;
            M[i] = num;
            while (i < M.size() and M[i+1] == num)
                i++;
        }
        return false;
    }
};
int main()
{
}