/*
You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < word.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a palindrome string.
Return an array of all the palindrome pairs of words.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};

int main()
{
}