/*

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                if (i + j < n and dp[i + j] != INT_MAX)
                {
                    dp[i] = min(dp[i + j] + 1, dp[i]);
                }
            }
        }
        return dp[0];
    }
};
int main()
{
}