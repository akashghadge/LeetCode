/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.





Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
Accepte
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, string> mp;
    void init()
    {
        int ptr = 0;
        int curr = 1;
        for (int i = 'a'; i <= 'z'; i++, ptr++)
        {
            if (i == 's' || i == 'z')
                ptr--;
            if (ptr % 3 == 0)
            {
                curr++;
            }
            mp[curr] += i;
        }
    }
    void help(string str, int curr, string ans, vector<string> &res)
    {
        if (curr == str.size())
        {
            res.push_back(ans);
            return;
        }
        for (auto ch : mp[str[curr] - '0'])
        {
            help(str, curr + 1, ans + ch, res);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        init();
        vector<string> res;
        if (digits.size() == 0)
        {
            return res;
        }
        help(digits, 0, "", res);
        return res;
    }
};
int main()
{
}