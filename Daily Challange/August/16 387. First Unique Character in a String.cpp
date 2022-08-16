/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,vector<int>>> mp;
        int i=0;
        for(auto val:s)
        {
            mp[val].first++;
            mp[val].second.push_back(i);
            i++;
        }
        int ans=INT_MAX;
        for(auto val:mp)
        {
            if(val.second.second.size()==1)
            {
                ans=min(ans,val.second.second[0]);
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};
int main()
{
}