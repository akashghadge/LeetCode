/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string str, string pat) {
        unordered_map<char,int> mp;
        for(auto ch:pat)
            mp[ch]++;
        for(auto ch:str)
        {
            // cout<<mp[ch]<<endl;
            if(mp.find(ch)!=mp.end() and mp[ch]>0)
                mp[ch]--;
            else
                return false;
        }
        return true;
    }
};
int main()
{
}