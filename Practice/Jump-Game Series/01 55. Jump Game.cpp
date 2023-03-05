#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &arr)
    {
        int n = arr.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= arr[i]; j++)
            {
                dp[i] = dp[i] or (j + i < n ? dp[j + i] : false);
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
int main()
{
}