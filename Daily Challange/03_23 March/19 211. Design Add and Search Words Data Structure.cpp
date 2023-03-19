/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 3 dots in word for search queries.
At most 104 calls will be made to addWord and search.

*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    bool word;
    TrieNode *children[26];
    TrieNode()
    {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(word.c_str(), root);
    }

private:
    TrieNode *root = new TrieNode();

    bool search(const char *word, TrieNode *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
            {
                node = node->children[word[i] - 'a'];
            }
            else
            {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->children[j];
                    if (search(word + i + 1, node))
                    {
                        return true;
                    }
                }
            }
        }
        return node && node->word;
    }
};

int main()
{
}