/*
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
 

Constraints:

1 <= words.length <= 104
1 <= words[i].length <= 30
words[i] consists of only lowercase English letters.
All the strings of words are unique.
1 <= sum(words[i].length) <= 105

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    unordered_set<string> wordSet{begin(words), end(words)};
    unordered_map<string, bool> memo;

    for (const string& word : words)
      if (isConcat(word, wordSet, memo))
        ans.push_back(word);

    return ans;
  }

 private:
  bool isConcat(const string& s, const unordered_set<string>& wordSet,
                unordered_map<string, bool>& memo) {
    if (memo.count(s))
      return memo[s];

    for (int i = 1; i < s.length(); ++i) {
      const string prefix = s.substr(0, i);
      const string suffix = s.substr(i);
      if (wordSet.count(prefix) &&
          (wordSet.count(suffix) || isConcat(suffix, wordSet, memo)))
        return memo[s] = true;
    }

    return memo[s] = false;
  }
};
    
int main()
{
}