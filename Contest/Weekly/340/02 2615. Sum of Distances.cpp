/*
You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.



Example 1:

Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation:
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5.
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3.
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4.
When i = 4, arr[4] = 0 because there is no other index with value 2.

Example 2:

Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109


*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;
    vector<long long> distance(vector<int> &a)
    {
        unordered_map<long long, pair<ll, ll>> left;
        unordered_map<ll, pair<ll, ll>> right;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            right[a[i]] = {right[a[i]].first + 1, right[a[i]].second + (i + 1)};
        }
        vector<long long> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            right[a[i]] = {right[a[i]].first - 1, right[a[i]].second - (i + 1)};
            if (right[a[i]].first == 0)
            {
                right.erase(a[i]);
            }
            if (left.find(a[i]) != left.end())
            {
                ll cn = left[a[i]].first;
                ll val = left[a[i]].second;
                ans[i] += abs(((i + 1) * cn) - val);
            }
            if (right.find(a[i]) != right.end())
            {
                ll cn = right[a[i]].first;
                ll val = right[a[i]].second;
                ans[i] += abs(((i + 1) * cn) - val);
            }
            left[a[i]] = {left[a[i]].first + 1, left[a[i]].second + i + 1};
        }
        return ans;
    }
};
int main()
{
}