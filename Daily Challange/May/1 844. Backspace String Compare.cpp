/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

Accepted
427,577
Submissions
898,245

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> ss;
        for(auto ch:t)
        {
            if(ch=='#' && st.size()!=0)
                st.pop();
            else if(ch!='#')
                st.push(ch);
        }
        for(auto ch:s)
        {
            if(ch=='#' && ss.size()!=0)
                ss.pop();
            else if(ch!='#')
                ss.push(ch);
        }
        return ss==st;
    }
};
int main()
{
}