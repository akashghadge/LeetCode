/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.



Example 1:


Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
Example 2:


Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.


Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxLength = -1;

    void getcycle(vector<int> &edges, int si, vector<bool> &visit, int size, vector<int> &store)
    {
        if (si == -1)
            return;
        if (visit[si])
        {
            int count = -1;
            for (int i = 0; i < store.size(); i++)
            {
                if (store[i] == si)
                {
                    count = i;
                    break;
                }
            }

            if (count == -1)
                return;
            maxLength = max(maxLength, size - count); // size-count gives the proper size of cycle
            return;
        }

        visit[si] = true;
        store.push_back(si);
        getcycle(edges, edges[si], visit, size + 1, store);

        return;
    }

    int longestCycle(vector<int> &edges)
    {

        vector<bool> visit(edges.size(), 0);
        for (int i = 0; i < edges.size(); i++)
        {

            if (visit[i])
                continue;
            vector<int> store;
            getcycle(edges, i, visit, 0, store);
        }

        return maxLength;
    }
};
int main()
{
}