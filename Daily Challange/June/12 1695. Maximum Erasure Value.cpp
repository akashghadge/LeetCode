/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pre;
    int get(int l,int r)
    {
        return pre[r+1]-pre[l];
    }
    int maximumUniqueSubarray(vector<int>& arr) {
        int n=arr.size();
        pre.resize(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+arr[i];
        }
        unordered_map<int,int> mp;
        for(auto val:arr)
            mp[val]=0;
        int start=0,end=1,mx=arr[0];
        mp[arr[0]]=1;
        for(;end<n;end++)
        {
            if(mp[arr[end]]==0)
            {
                mp[arr[end]]++;
                mx=max(mx,get(start,end));
            }
            else
            {
                mp[arr[end]]++;
                while(mp[arr[end]]>1)
                {
                    mp[arr[start]]--;
                    start++;
                }
                mx=max(mx,get(start,end));
            }
        }
        return mx;
    }
};
int main()
{
}