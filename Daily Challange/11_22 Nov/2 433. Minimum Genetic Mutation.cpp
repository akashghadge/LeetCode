/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(string a,string b)
    {
        bool f=1;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i] and f)
                f=0;
            else if(a[i]!=b[i])
                return 0;
        return 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st;
        for(auto val:bank)
            st.insert(val);
        queue<pair<string,int>> q;
        q.push({start,0});
        int ans=INT_MAX;
        while(q.size())
        {
            auto curr=q.front();
            q.pop();
            st.erase(curr.first);
            if(curr.first==end) ans=min(ans,curr.second);
            for(auto pos:st)
                if(valid(pos,curr.first))
                    q.push({pos,curr.second+1});
        }
        return ans==INT_MAX?-1:ans;
    }
};
int main()
{
}