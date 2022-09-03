/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Constraints:

2 <= n <= 9
0 <= k <= 9

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void help(int n,int k,string curr,vector<int>&ans)
    {
        if(n==0)
        {
            if(curr[0]!='0')
            {
                int num=stoi(curr);  
                // cout<<curr<<endl;
                ans.push_back(num);
            }
            return;
        }
        for(int i=0;i<=9;i++)
        {
            if(curr.size()==0)
            {
                curr.push_back('0'+i);
                help(n-1,k,curr,ans);
                curr.pop_back();
            }
            else if(curr.size()!=0)
            {      
                if(abs((curr.back()-'0')-i)==k)
                {                    
                    curr+=to_string(i);
                    // cout<<curr<<endl;
                    help(n-1,k,curr,ans);
                    curr.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        help(n,k,"",ans);
        return ans;
    }
};
int main()
{
}