/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""


Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.length() < str2.length())
        {
            return gcd(str2, str1);
        }

        // If str1 is not the
        // concatenation of str2
        else if (str1.find(str2) != 0)
        {
            return "";
        }
        else if (str2 == "")
        {

            // GCD string is found
            return str1;
        }
        else
        {

            // Cut off the common prefix
            // part of str1 & then recur
            return gcd(str1.substr(str2.length()), str2);
        }
    }
};
int main()
{
}