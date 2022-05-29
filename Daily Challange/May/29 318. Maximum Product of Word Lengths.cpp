/*
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
 

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(set<char> &f,set<char>&s)
    {
        for(auto val:f)
            if(s.find(val)!=s.end())
                return false;
        return true;
    }
    int maxProduct(vector<string>& words) {
        vector<set<char>> arr;
        for(auto word:words)
        {
            set<char> curr;
            for(auto ch:word)
            {
                curr.insert(ch);
            }
            arr.push_back(curr);
        }
        int n=words.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans=words[i].size()*words[j].size();
                if(valid(arr[i],arr[j]))
                    mx=max(mx,ans);
            }
        }
        return mx;
    }
};
int main()
{
}