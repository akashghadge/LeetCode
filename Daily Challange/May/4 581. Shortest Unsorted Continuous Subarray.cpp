/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.



Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0


Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105



*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int start = -1, end = -1, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max > nums[i])
            {
                if (start == -1)
                    start = i - 1;
                while (start - 1 >= 0 && nums[start - 1] > nums[i])
                    start--;
                end = i + 1;
            }
            else
                max = nums[i];
        }
        return end - start;
    }
};
int main()
{
}