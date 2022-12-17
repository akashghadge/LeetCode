/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.



Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22


Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &A)
    {
        stack<long long> st;
        for (long long i = 0; i < A.size(); i++)
        {
            if (A[i] != "+" && A[i] != "-" && A[i] != "/" && A[i] != "*")
            {
                st.push(stoi(A[i]));
                continue;
            }
            else
            {
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                if (A[i] == "+")
                    st.push(a + b);
                else if (A[i] == "-")
                    st.push(a - b);
                else if (A[i] == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
        }
        return st.top();
    }
};
int main()
{
}