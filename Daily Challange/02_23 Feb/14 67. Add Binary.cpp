/*
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0, sum;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = sum >= 2 ? carry = 1 : carry = 0;
            res += ((sum % 2) + '0');
            i--, j--;
        }
        while (i >= 0)
        {
            sum = (a[i] - '0') + carry;
            carry = sum >= 2 ? carry = 1 : carry = 0;
            res += ((sum % 2) + '0');
            i--;
        }
        while (j >= 0)
        {
            sum = (b[j] - '0') + carry;
            carry = sum >= 2 ? carry = 1 : carry = 0;
            res += ((sum % 2) + '0');
            j--;
        }
        if (carry == 1)
        {
            res += carry + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};  
int main()
{
}