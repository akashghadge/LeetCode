/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.



Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxVowels(string str, int k)
    {
        int cn = 0, n = str.size(), ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u')
            {
                cn++;
            }
        }
        ans = max(cn, ans);
        for (int i = k; i < n; i++)
        {
            if (str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u')
                cn++;
            if (str[i - k] == 'a' or str[i - k] == 'e' or str[i - k] == 'i' or str[i - k] == 'o' or str[i - k] == 'u')
                cn--;
            ans = max(cn, ans);
        }
        return ans;
    }
};
int main()
{
}