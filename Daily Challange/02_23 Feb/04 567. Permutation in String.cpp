/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> pat;
        unordered_map<char, int> mp;
        for (auto val : s1)
            pat[val]++;
        int m = s1.size();
        int n = s2.size();
        if (n < m)
            return false;
        for (int i = 0; i < m; i++)
        {
            mp[s2[i]]++;
        }
        if (mp == pat)
            return true;
        for (int i = m; i < n; i++)
        {
            mp[s2[i]]++;
            mp[s2[i - m]]--;
            if (mp[s2[i - m]] == 0)
                mp.erase(s2[i - m]);
            if (mp == pat)
                return true;
        }
        return mp == pat;
    }
};
int main()
{
}