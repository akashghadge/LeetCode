/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.



Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return isp(s, i + 1, j) || isp(s, i, j - 1);
        return true;
    }

private:
    bool isp(string s, int l, int r)
    {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};

int main()
{
}