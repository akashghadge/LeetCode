/*
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.



Example 1:



Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
Example 2:



Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.


Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        const int n = colors.length();
        int ans = 0;
        int processed = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegree(n);
        queue<int> q;
        vector<vector<int>> count(n, vector<int>(26));

        // Build graph
        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].push_back(v);
            ++inDegree[v];
        }

        // Topology
        for (int i = 0; i < n; ++i)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            const int out = q.front();
            q.pop();
            ++processed;
            ans = max(ans, ++count[out][colors[out] - 'a']);
            for (const int in : graph[out])
            {
                for (int i = 0; i < 26; ++i)
                    count[in][i] = max(count[in][i], count[out][i]);
                if (--inDegree[in] == 0)
                    q.push(in);
            }
        }

        return processed == n ? ans : -1;
    }
};

int main()
{
}