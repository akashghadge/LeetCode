/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).


Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
0 <= index < nums.length
-100 <= val <= 100
0 <= left <= right < nums.length
At most 3 * 104 calls will be made to update and sumRange.

*/
#include <bits/stdc++.h>
using namespace std;
class NumArray
{
public:
    vector<int> seg; // Segment Tree to be stored in a vector.
    int n;           // Length of the segment tree vector.
    void buildTree(vector<int> &nums, int pos, int left, int right)
    {
        if (left == right)
        {
            seg[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
    void updateUtil(int pos, int left, int right, int index, int val)
    {
        if (index < left || index > right)
            return;

        if (left == right)
        {
            if (left == index)
                seg[pos] = val;
            return;
        }
        int mid = (left + right) / 2;
        updateUtil(2 * pos + 1, left, mid, index, val);      // left child
        updateUtil(2 * pos + 2, mid + 1, right, index, val); // right child
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    int rangeUtil(int qlow, int qhigh, int low, int high, int pos)
    {
        if (qlow <= low && qhigh >= high)
        { // total overlap
            return seg[pos];
        }
        if (qlow > high || qhigh < low)
        { // no overlap
            return 0;
        }
        int mid = low + (high - low) / 2;
        return (rangeUtil(qlow, qhigh, low, mid, 2 * pos + 1) + rangeUtil(qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }

    NumArray(vector<int> &nums)
    {
        if (nums.size() > 0)
        {
            n = nums.size();
            seg.resize(4 * n, 0);         // Maximum size of a segment tree for an array of size n is 4n
            buildTree(nums, 0, 0, n - 1); // Build the segment tree
        }
    }

    void update(int index, int val)
    {
        if (n == 0)
            return;
        updateUtil(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        if (n == 0)
            return 0;
        return rangeUtil(left, right, 0, n - 1, 0);
    }
};
int main()
{
}