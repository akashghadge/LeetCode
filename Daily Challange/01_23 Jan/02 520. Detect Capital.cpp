/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool f='A'<=word[0] and word[0]<='Z';
        int cn=0;
        for(int i=1;i<word.size();i++)
        {
            if('A'<=word[i] and word[i]<='Z')
                cn++;
        }
        if(!f and cn==0)
            return true;
        if(f and cn==word.size()-1)
            return true;
        if(f and cn==0)
            return true;
        return false;
    }
};
int main()
{
}