/*

*/
#include <bits/stdc++.h>
using namespace std;
/*
@important
here for tracking visited elements we can mark them negative cause by constrained array is positive only (saving extra space)
*/
bool canReach(vector<int> &A, int i)
{
    return 0 <= i && i < A.size() && A[i] >= 0 && (!(A[i] = -A[i]) || canReach(A, i + A[i]) || canReach(A, i - A[i]));
}
class Solution
{
public:
    void dfs(int src, vector<int> &arr, vector<int> &vis)
    {
        if (src < 0 or src >= arr.size())
            return;
        if (vis[src])
            return;
        vis[src] = 1;
        dfs(src + arr[src], arr, vis);
        dfs(src - arr[src], arr, vis);
    }
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        dfs(start, arr, vis);
        int target = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 and vis[i])
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
}