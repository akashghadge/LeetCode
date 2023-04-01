/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        if (arr.size() == 1)
        {
            return (arr[0] == target) ? 0 : -1;
        }
        int lo = 0;
        int hi = arr.size();
        int ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
}