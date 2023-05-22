/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.


Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto val : nums)
            mp[val]++;
        vector<pair<int, int>> ans;
        for (auto val : mp)
        {
            pair<int, int> curr = {val.second, val.first};
            ans.push_back(curr);
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        int i = 0;
        vector<int> res;
        for (auto val : ans)
        {
            res.push_back(val.second);
            i++;
            if (i >= k)
                break;
        }
        return res;
    }
};
int main()
{
}