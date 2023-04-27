#include <bits/stdc++.h>
using namespace std;
#define en "\n"
#define ll long long
#define v vector
#define vi vector<int>
#define vll vector<ll>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    typedef vector<vector<int>> vii;
    bool dfs(int src, int dest, vii &graph, vector<int> &visited, vii &arr)
    {
        visited[src] = true;
        for (auto nbr : graph[src])
        {
            if (!visited[nbr])
            {
                if (src == nbr || dfs(nbr, dest, graph, visited, arr))
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> arr(n);
        vector<vector<int>> graph(n);
        for (auto val : edges)
        {
            graph[val[0]].push_back(val[1]);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n);
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                if (!visited[j] && dfs(j, i, graph, visited, arr))
                {
                    arr[i].push_back(j);
                }
            }
        }
        return arr;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;

    return 0;
}