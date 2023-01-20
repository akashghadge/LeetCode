/*
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.



Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]


Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(nums, 0, {}, ans);
        return ans;
    }

private:
    void dfs(const vector<int> &nums, int s, vector<int> &&path,
             vector<vector<int>> &ans)
    {
        if (path.size() > 1)
            ans.push_back(path);

        unordered_set<int> used;

        for (int i = s; i < nums.size(); ++i)
        {
            if (used.count(nums[i]))
                continue;
            if (path.empty() || nums[i] >= path.back())
            {
                used.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1, move(path), ans);
                path.pop_back();
            }
        }
    }
};

int main()
{
}