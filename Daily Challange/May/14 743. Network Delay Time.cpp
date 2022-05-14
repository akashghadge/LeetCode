/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.



Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1


Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/
#include <bits/stdc++.h>
using namespace std;
#define vpi vector<vector<pair<int, int>>>
struct Node
{
    int src, sum;
    Node(int s, int sm)
    {
        src = s;
        sum = sm;
    }
};
struct comparator
{
    bool operator()(Node *a, Node *b) { return a->sum > b->sum; }
};
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vpi graph(n);
        k--;
        for (auto time : times)
        {
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> visited(n, 0);
        priority_queue<Node *, vector<Node *>, comparator> q;
        q.push(new Node(k, 0));
        int ans = INT_MIN;
        while (q.size())
        {
            Node *curr = q.top();
            q.pop();
            if (visited[curr->src])
                continue;
            visited[curr->src] = true;
            ans = max(ans, curr->sum);
            for (auto nbr : graph[curr->src])
            {
                q.push(new Node(nbr.first, curr->sum + nbr.second));
            }
        }
        for (auto val : visited)
            if (val == 0)
                return -1;
        return ans;
    }
};
int main()
{
}