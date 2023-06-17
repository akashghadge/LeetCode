/*
        1187. Make Array Strictly Increasing


        Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.


Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].


Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].


Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.


Constraints:


        1 <= arr1.length, arr2.length <= 2000
        0 <= arr1[i], arr2[i] <= 10^9
        */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
        int solve(int i, int j, int &a, int &b, int p, vector<vector<int>> &dp, vector<int> &v1, vector<int> &v2)
        {
                if (i == a)
                {
                        return 0;
                }
                j = upper_bound(v2.begin() + j, v2.end(), p) - v2.begin();
                if (dp[i][j] != -1)
                        return dp[i][j];
                if (j == b && v1[i] <= p)
                        return 2001;
                int take = 2001, nottake = 2001;
                if (j != b)
                        take = solve(i + 1, j + 1, a, b, v2[j], dp, v1, v2) + 1;
                if (v1[i] > p)
                        nottake = solve(i + 1, j, a, b, v1[i], dp, v1, v2);
                return dp[i][j] = min(take, nottake);
        }
        int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
        {
                int n = arr1.size(), m = arr2.size();
                vector<vector<int>> dp(2001, vector<int>(2001, -1));
                sort(arr2.begin(), arr2.end());
                int a = solve(0, 0, n, m, -1, dp, arr1, arr2);
                if (a > n)
                        return -1;
                return a;
        }
};