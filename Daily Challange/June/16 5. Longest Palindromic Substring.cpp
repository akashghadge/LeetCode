/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string str) {
        int n=str.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        string ans="";
        int i_ans=0;
        int j_ans=0;
        int l=INT_MIN;
        for(int gap=0;gap<n;gap++)
        {
            for(int j=gap,i=0;j<n;j++,i++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    char ch1=str[i];
                    char ch2=str[j];
                    if(ch1 == ch2)
                        dp[i][j]=2;
                }
                else
                {
                    char ch1=str[i];
                    char ch2=str[j];
                    if(ch1==ch2 and dp[i+1][j-1])
                        dp[i][j]=dp[i+1][j-1] + 2;
                }
                if(l<dp[i][j])
                {
                    l=dp[i][j];
                    ans=str.substr(i,gap+1);
                }
            }
        }
        return ans;
    }
};
int main()
{
}