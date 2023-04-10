/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='(' || s[i]== '[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
            if(!st.empty()){
                if(s[i]==')'){
                    char temp=st.top();
                    if(temp=='('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]==']'){
                    char temp=st.top();
                    if(temp=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]=='}'){
                    char temp=st.top();
                    if(temp=='{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                return false;
            }
        }
       
            i++;
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
int main()
{
}