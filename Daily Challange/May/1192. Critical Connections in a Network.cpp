/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> adjList;
    vector<vector<int>> bridges;
    vector<int> disc, low, parent;
    int time;
    void DFSHelper(int node) {
        disc[node] = low[node] = time++;
        
        for(int i = 0; i < adjList[node].size(); ++i)
        {
            int child = adjList[node][i];
            if(disc[child] == -1)
            {
                parent[child] = node;
                DFSHelper(child);
                
                low[node] = min(low[node],low[child]);
                
                if(low[child] > disc[node])
                    bridges.push_back({node,child});
            }
            else if(child != parent[node])
                low[node] = min(low[node],disc[child]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adjList.resize(n);
        disc.resize(n,-1);
        low.resize(n,-1);
        parent.resize(n,-1);
        time = 0;
        
        for(auto& conn : connections)
        {
            adjList[conn[1]].push_back(conn[0]);
            adjList[conn[0]].push_back(conn[1]);
        }

        for(int i = 0; i < n; ++i)
            if(disc[i] == -1)
                DFSHelper(i);
        
        return bridges;
    }
};

int main()
{
}