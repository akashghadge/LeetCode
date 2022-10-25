/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.



Example 1:

Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
Example 2:

Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
Example 3:

Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true


Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int i = 0, j = 0, ptr1 = 0, ptr2 = 0, n = word1.size(), m = word2.size();
        while (i < n and j < m)
        {
            int ln = word1[i].size(), lm = word2[j].size();
            if (word1[i][ptr1] != word2[j][ptr2])
                return false;
            ptr1++, ptr2++;
            if (ptr1 == ln)
                i++, ptr1 = 0;
            if (ptr2 == lm)
                j++, ptr2 = 0;
        }
        return (i == n and j == m);
    }
};
int main()
{
}