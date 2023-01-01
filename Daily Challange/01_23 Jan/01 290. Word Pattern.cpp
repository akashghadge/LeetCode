/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<string,char> a;
        unordered_map<char,string> b;
        int n=s.size();
        int m=p.size();
        string curr="";
        int j=0;
        int i=0;
        for(i=0;i<n and j<m;i++)
        {
            if(s[i]==' ')
            {
                if(curr.size()!=0)
                {
                    if(a.find(curr)!=a.end() and b.find(p[j])!=b.end())
                    {
                        if(a[curr] != p[j] or b[p[j]]!=curr)
                            return false;
                    }
                    else if(a.find(curr)!=a.end() or b.find(p[j])!=b.end())
                    {
                        return false;
                    }
                    else
                    {
                        a[curr]=p[j];
                        b[p[j]]=curr;
                    }
                    j++;
                    curr="";
                }
            }
            else
            {
                curr+=s[i];
            }
        }
        // cout<<curr<<" ";
        if(curr.size()!=0)
        {
            if(a.find(curr)!=a.end() and b.find(p[j])!=b.end())
            {
                if(a[curr] != p[j] or b[p[j]]!=curr)
                    return false;
            }
            else if(a.find(curr)!=a.end() or b.find(p[j])!=b.end())
            {
                return false;
            }
            else
            {
                a[curr]=p[j];
                b[p[j]]=curr;
            }
            j++;
            curr="";
        }
        return i==n and j==m;
    }
};
int main()
{
}