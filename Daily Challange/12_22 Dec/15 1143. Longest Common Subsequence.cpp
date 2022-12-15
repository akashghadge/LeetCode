/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int i1 = 0, i2 = 0;
        
        for(int i1 = 0; i1 < m; i1++){
            for(int i2 = 0; i2 < n; i2++){
                if(text1[i1] == text2[i2]){
                    dp[i1][i2] = ((i1 > 0 && i2 > 0) ? dp[i1-1][i2-1] : 0) + 1;
                }else{
                    dp[i1][i2] = max(((i1 > 0) ? dp[i1-1][i2] : 0), 
                                     ((i2 > 0) ? dp[i1][i2-1] : 0));
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

int main()
{
}