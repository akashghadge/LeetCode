/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i])!=mp.end() and abs(mp[arr[i]]-i)<=k)
                return true;
            // if(mp.find(arr[i])==mp.end())
                mp[arr[i]]=i;
        }
        return false;
    }
};
int main()
{
}