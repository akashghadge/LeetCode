/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) 
    {
        int i=0 ;
        int j=s.size() ;
        while(i<j)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' 
            || s[i]=='U' )
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' 
                || s[j]=='U')
                 {
                      swap(s[i],s[j]) ;
                      i++ ;
                      j-- ;
                 }
                 else
                 {
                     j-- ;
                 }
            }
            else
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' 
                || s[j]=='U')
                {
                    i++ ;
                }
                else{
                    i++ ;
                    j-- ;
                }
            }
        } 
        return s ;  
    }
};

int main()
{
}