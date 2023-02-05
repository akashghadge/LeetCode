/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> a;
        unordered_map<char, int> b;
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m)
            return ans;
        for (auto ch : p)
            b[ch]++;
        for (int i = 0; i < m; i++)
        {
            a[s[i]]++;
        }
        if (b == a)
            ans.push_back(0);
        for (int i = m; i < n; i++)
        {
            a[s[i]]++;
            a[s[i - m]]--;
            if (a[s[i - m]] == 0)
                a.erase(s[i - m]);
            if (a == b)
                ans.push_back(i - m + 1);
        }
        return ans;
    }
};
int main()
{
}