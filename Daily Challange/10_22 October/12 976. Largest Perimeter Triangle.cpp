/*
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Example 2:

Input: nums = [1,2,1]
Output: 0
 

Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=n-3;i>=0;i--)
        {
            if(arr[i+2]<arr[i+1]+arr[i])
                return arr[i+2]+arr[i+1]+arr[i];
        }
        return 0;
    }
};
int main()
{
}