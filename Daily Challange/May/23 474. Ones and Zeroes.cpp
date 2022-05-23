/*
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

Constraints:

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size() + 1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(strs, 0, m, n);
    }
    
    int solve(vector<string>& strs, int i, int m , int n) {
        //base condition 1
        if(m < 0 || n < 0)
            return -1 * 1e7;
        //base condition 2
        if(i == strs.size())
            return 0;
        // return ans if already computed.
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        // consider current str;
        int m1 = 0, n1 = 0;
        for(int j = 0; j < strs[i].length(); j++) {
            if(strs[i][j] == '1')
                n1++;
            else
                m1++;
        }
        
        // calculate ans recursively.
        
        return dp[i][m][n] = max(solve(strs,i+1, m, n), 1 + solve(strs, i+1, m-m1, n-n1));
        
    }
    
};

int main()
{
}