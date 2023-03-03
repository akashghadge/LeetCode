/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> get_lps(string pat)
    {
        int n = pat.size();
        vector<int> lps(n);
        int len = 0;
        int i;
        lps[0] = 0;
        i = 1;
        while (i < n)
        {
            if (pat[i] == pat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int strStr(string str, string pat)
    {
        vector<int> lps = get_lps(pat);
        int n = str.size();
        int m = pat.size();
        int i = 0;
        int j = 0;
        while ((n - i) >= (m - j))
        {
            if (pat[j] == str[i])
            {
                j++;
                i++;
            }

            if (j == m)
            {
                return i - j;
                j = lps[j - 1];
            }

            else if (i < n && pat[j] != str[i])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return -1;
    }
};
int main()
{
}