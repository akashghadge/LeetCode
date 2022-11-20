/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNum(char c) {
        return c >= '0' and c <= '9';
    }
    int helper(string s) {
        vector<int> res; vector<bool> plus; 
        int curridx = 0; int n = s.size(), idx = 0;
        res.push_back(0); plus.push_back(1);
        while(idx < n) {
            if(s[idx] == '(') {
                res.push_back(0), plus.push_back(1);
                curridx++, idx++;
            }
            else if(s[idx] == ')') {
                int val = res.back(); res.pop_back(); curridx--; plus.pop_back();
                if(plus[curridx]) res[curridx] += val;
                else res[curridx] -= val;
                idx++;
            }
            else if(isNum(s[idx])) {
                int val = 0;
                while(idx < n and isNum(s[idx])) {
                    val = (val * 10) + (s[idx] - '0');
                    idx++;
                }
                if(plus[curridx]) res[curridx] += val;
                else res[curridx] -= val;
            }
            else if(s[idx] == '-') plus[curridx] = 0, idx++;
            else plus[curridx] = 1, idx++;
        }
        return res[curridx];
    }
    int calculate(string s) {
        string res = "";
        for(char c : s) {
            if(c - ' ') res.push_back(c);
        }
        return helper(res);
    }
};
int main()
{
}