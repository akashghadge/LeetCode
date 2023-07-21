/*
        673. Number of Longest Increasing Subsequence
        

        Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 
Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].


Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


 
Constraints:


	1 <= nums.length <= 2000
	-106 <= nums[i] <= 106
        */
        

        #include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;typedef long double ld;typedef pair<ll, ll> ii;typedef vector<ll> vi;typedef vector<vi> vvi;typedef vector<string> vvs;typedef vector<ii> vii;typedef vector<char> vch;typedef vector<string> vs;class Solution {public:    int findNumberOfLIS(vector<int>& arr) {        int n = arr.size(), maxi = 1;        vector<int> dp(n, 1), ct(n, 1);        for (int i = 0; i <= n - 1; i++)        {            for (int prev_index = 0; prev_index <= i - 1; prev_index++)            {                if (arr[prev_index] < arr[i] && dp[prev_index] + 1 > dp[i])                {                    dp[i] = dp[prev_index] + 1;                    ct[i] = ct[prev_index];                }                else if (arr[prev_index] < arr[i] && dp[prev_index] + 1 == dp[i])                {                    ct[i] = ct[i] + ct[prev_index];                }            }            maxi = max(maxi, dp[i]);        }        int nos = 0;        for (int i = 0; i <= n - 1; i++)            if (dp[i] == maxi)                nos += ct[i];        return nos;    }};
