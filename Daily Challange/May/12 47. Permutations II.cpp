/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        vector<vector<int>> results;
        unordered_map<int,int> mp;
        for (int num : nums)
            mp[num]++;

        vector<int> comb;
        backtrack(comb, nums.size(), mp, results);
        return results;
    }

     void backtrack(vector<int> comb,int N,
            unordered_map<int,int> mp,vector<vector<int>>& results) {

        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }

        for (auto val:mp) {
            int count=val.second;
            int num=val.first;
            if (count == 0)
                continue;
            comb.push_back(num);
            mp[num]--;
            backtrack(comb, N, mp, results);
            comb.pop_back();
            mp[num]=count;
        }
    }
};
int main()
{
}