/*
Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.


Example 1:

Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]

Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".


Constraints:

1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.

*/
#include <bits/stdc++.h>
using namespace std;
class trie
{
    trie *ch[27];
    int weight;

public:
    trie()
    {
        memset(ch, 0, sizeof(ch));
        weight = 0;
    }
    void insert(string str, int weight)
    {
        trie *node = this;
        for (char c : str)
        {
            if (node->ch[c - 'a'] == NULL)
                node->ch[c - 'a'] = new trie();
            node = node->ch[c - 'a'];
            node->weight = weight;
        }
    }
    int startsWith(string str)
    {
        trie *node = this;
        for (char c : str)
        {
            if (node->ch[c - 'a'] == NULL)
                return -1;
            node = node->ch[c - 'a'];
        }
        return node->weight;
    }
};
class WordFilter
{
public:
    trie root;
    WordFilter(vector<string> &words)
    {
        int idx = 0;
        for (string word : words)
        {
            root.insert(word, idx);
            string tmp = "{" + word;
            for (int i = word.length() - 1; i >= 0; i--)
            {
                string newword = word[i] + tmp;
                tmp = newword;
                root.insert(newword, idx);
            }
            idx++;
        }
    }

    int f(string prefix, string suffix)
    {
        string word = suffix + "{" + prefix;
        return root.startsWith(word);
    }
};
int main()
{
}