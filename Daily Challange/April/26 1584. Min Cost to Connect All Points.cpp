/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.

*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define ll long long
#define v vector
#define pii pair<int, int>
class Solution
{
public:
    struct Node
    {
        int src, wt;
        int parent;
        Node(int s, int p, int w)
        {
            src = s;
            wt = w;
            parent = p;
        }
    };
    struct compare
    {
        bool operator()(Node *p1, Node *p2)
        {
            return p1->wt > p2->wt;
        }
    };
    int sol(v<v<pii>> graph, int src)
    {
        vi visited(graph.size());
        priority_queue<Node *, vector<Node *>, compare> pq;
        pq.push(new Node(src, -1, 0));
        int ans = 0;
        while (pq.size() > 0)
        {
            Node *node = pq.top();
            pq.pop();
            if (visited[node->src])
                continue;

            visited[node->src] = true;
            if (node->parent != -1)
                ans += node->wt;

            for (auto nbr : graph[node->src])
            {
                if (visited[nbr.first])
                    continue;
                pq.push(new Node(nbr.first, node->src, nbr.second));
            }
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        v<v<pii>> arr(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                arr[i].push_back({j, dist});
                arr[j].push_back({i, dist});
            }
        }
        return sol(arr, 0);
    }
};
int main()
{
}