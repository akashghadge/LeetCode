/*
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
 

Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string>res;
        map<char,vector<int>>m1;
        int n=p.length();
        for(int i=0;i<n;i++)
        {
            m1[p[i]].push_back(i);
        }
        
       
        for(int k=0;k<words.size();k++)
        {
            string s=words[k];
            map<char,vector<int>>m2;
            for(int i=0;i<n;i++)
            {
                m2[s[i]].push_back(i);
            }
            int f=1;
            
           for(int i=0;i<n;i++)
           {
               vector<int>temp1=m2[s[i]];
               vector<int>temp2=m1[p[i]];
               if(temp1.size()!=temp2.size())
               {
                   f=0;
                   break;
               }
               for(int j=0;j<temp1.size();j++)
               {
                   if(temp1[j]!=temp2[j])
                   {
                       f=0;
                       break;
                   }
               }
           }
            if(f==1)
            {
                res.push_back(s);
            }
        }
        return res;
    }
};
int main()
{
}