/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        buildSortedIndexes(arr);
        return calcRanges(arr);
    }
    
    void buildSortedIndexes(const vector<int> &arr) {
        sortedIndexes.resize(arr.size());
        std::iota(sortedIndexes.begin(), sortedIndexes.end(), 0);
        std::sort(sortedIndexes.begin(), sortedIndexes.end(), [&](const auto &lhs, const auto &rhs) -> bool {
            return arr[lhs] < arr[rhs];
        });
    }
    
    int calcRanges(const vector<int> &arr) {
        long ans = 0;
        for (int si = 0; si < sortedIndexes.size(); si++) {
            const int i = sortedIndexes[si];
            const auto &[left, right] = findLeftRightDisabledIndexes(arr, i);
            const long numRanges = (i - left) * (right - i);
            ans += numRanges * arr[i];
            ans %= MOD_VALUE;
            disabledIndexes.insert(i);
        }
        return ans;
    }
    
    pair<int, int> findLeftRightDisabledIndexes(const vector<int> &arr, const int i) {
        int left = -1;
        int right = arr.size();
        auto itRight = disabledIndexes.upper_bound(i);
        if (itRight != disabledIndexes.end()) right = *itRight;
        if (itRight != disabledIndexes.begin()) {
            const auto itLeft = --itRight;
            left = *itLeft;
        }
        return {left, right};
    }
    
    const int MOD_VALUE = 1000000000 + 7;
    vector<int> sortedIndexes;
    set<int> disabledIndexes;
};

int main()
{
}