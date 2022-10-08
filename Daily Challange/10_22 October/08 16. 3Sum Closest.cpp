/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=-1;
        int ab=INT_MAX;
        for(int k=0;k<n;k++)
        {
            int i=k+1,j=n-1;
            while(i<j)
            {
                int curr=arr[i]+arr[j]+arr[k];
                if(curr==target)
                {
                    ab=abs(curr-target);
                    ans=target;
                    return target;
                }
                else if(curr<target)
                {
                    if(ab>abs(curr-target))
                    {
                        ans=curr;
                        ab=abs(curr-target);
                    }
                    i++;
                }
                else
                {
                    if(ab>abs(curr-target))
                    {
                        ans=curr;
                        ab=abs(curr-target);
                    }
                    j--;
                }
            }
        }
        return ans;
    }
    
};
int main()
{
}