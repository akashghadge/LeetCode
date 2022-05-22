/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSubstrings(string str)
    {
        vector<vector<int>> dp(str.size(), vector<int>(str.size(), 0));
        int n = str.size();
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1 && str[i] == str[j])
                {
                    dp[i][j] = 1;
                }
                else if (str[i] == str[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = 1;
                }
            }
        }
        int cnt = 0;
        for (auto val : dp)
            for (auto curr : val)
                if (curr)
                    cnt++;
        return cnt;
    }
};
int main()
{
}