/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?


*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
            return "";
        unordered_map<int, int> map;
        for (char c : t)
        {
            map[c]++;
        }

        vector<int> indices;
        for (int index = 0; index < s.size(); index++)
        {
            if (map.find(s[index]) != map.end())
            {
                indices.push_back(index);
            }
        }

        string best_result;
        unordered_map<int, int> P = map;
        unordered_map<int, int> N;
        int left = 0, right = 0;

        while (right < indices.size())
        {
            while (right < indices.size() && P.size() > 0)
            {
                int index = indices[right];
                char c = s[index];
                if (P.find(c) != P.end())
                {
                    P[c]--;
                    if (P[c] == 0)
                    {
                        P.erase(c);
                    }
                }
                else
                {
                    N[c]--;
                }

                right++;
            }

            bool solution_exists = P.size() == 0;

            while (P.size() == 0)
            {
                int index = indices[left];
                char c = s[index];
                if (N.find(c) != N.end())
                {
                    N[c]++;
                    if (N[c] == 0)
                    {
                        N.erase(c);
                    }
                }
                else
                {
                    P[c]++;
                }

                left++;
            }

            if (solution_exists)
            {
                string current_result = s.substr(indices[left - 1], indices[right - 1] - indices[left - 1] + 1);
                if (best_result.size() == 0 || current_result.size() < best_result.size())
                {
                    best_result = current_result;
                }
            }
        }
        return best_result;
    }
};
int main()
{
}