/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 

Example 1:


Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
Example 2:


Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.
Example 3:


Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
 

Constraints:

n == vals.length
1 <= n <= 3 * 104
0 <= vals[i] <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.

*/
#include <bits/stdc++.h>
using namespace std;
class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(begin(id), end(id), 0);
  }

  void unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (rank[i] < rank[j]) {
      id[i] = id[j];
    } else if (rank[i] > rank[j]) {
      id[j] = id[i];
    } else {
      id[i] = id[j];
      ++rank[j];
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> id;
  vector<int> rank;
};

class Solution {
 public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    const int n = vals.size();
    int ans = n;
    UnionFind uf(n);
    vector<vector<int>> graph(n);
    map<int, vector<int>> valToNodes;

    for (int i = 0; i < vals.size(); ++i)
      valToNodes[vals[i]].push_back(i);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      if (vals[v] <= vals[u])
        graph[u].push_back(v);
      if (vals[u] <= vals[v])
        graph[v].push_back(u);
    }

    for (const auto& [val, nodes] : valToNodes) {
      for (const int u : nodes)
        for (const int v : graph[u])
          uf.unionByRank(u, v);
      unordered_map<int, int> rootCount;
      for (const int u : nodes)
        ++rootCount[uf.find(u)];
      // For each group, C(count, 2) := count * (count - 1) / 2
      for (const auto& [_, count] : rootCount)
        ans += count * (count - 1) / 2;
    }

    return ans;
  }
};

int main()
{
}