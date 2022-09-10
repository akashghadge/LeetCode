/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1 || n == 0)
            return 0;
        vii dp(k + 1, vi(n));
        for (int transaction = 1; transaction <= k; transaction++)
        {
            int max_profit_one_less = INT_MIN;
            for (int day = 1; day < n; day++)
            {
                max_profit_one_less = max(max_profit_one_less, dp[transaction - 1][day - 1] - prices[day - 1]);
                dp[transaction][day] = max(dp[transaction][day - 1], max_profit_one_less + prices[day]);
            }
        }
        return dp[k][n - 1];
    }
};
int main()
{
}