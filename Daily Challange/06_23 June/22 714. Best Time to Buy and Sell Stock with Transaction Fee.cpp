/*
        714. Best Time to Buy and Sell Stock with Transaction Fee


        You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:


        You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
        The transaction fee is only charged once for each stock purchase and sale.



Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.


Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6



Constraints:


        1 <= prices.length <= 5 * 104
        1 <= prices[i] < 5 * 104
        0 <= fee < 5 * 104
        */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vvs;
typedef vector<ii> vii;
typedef vector<char> vch;
typedef vector<string> vs;
class Solution
{
public:
        int maxProfit(vector<int> &Arr, int fee)
        {
                int n = Arr.size();
                vector<ll> ahead(2, 0);
                vector<ll> cur(2, 0); // base condition
                ahead[0] = ahead[1] = 0;
                ll profit;
                for (int ind = n - 1; ind >= 0; ind--)
                {
                        for (int buy = 0; buy <= 1; buy++)
                        {
                                if (buy == 0)
                                {
                                        // We can buy the stock
                                        profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
                                }
                                if (buy == 1)
                                {
                                        // We can sell the stock
                                        profit = max(0 + ahead[1], Arr[ind] - fee + ahead[0]);
                                }
                                cur[buy] = profit;
                        }
                        ahead = cur;
                }
                return cur[0];
        }
};
