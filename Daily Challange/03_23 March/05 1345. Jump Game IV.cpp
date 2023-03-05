/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.



Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.


Constraints:

1 <= arr.length <= 5 * 104
-108 <= arr[i] <= 108

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        const int n = arr.size();
        // {a: indices}
        unordered_map<int, vector<int>> graph;
        queue<int> q{{0}};
        vector<bool> seen(n);
        seen[0] = true;

        for (int i = 0; i < n; ++i)
            graph[arr[i]].push_back(i);

        for (int steps = 0; !q.empty(); ++steps)
        {
            for (int sz = q.size(); sz > 0; --sz)
            {
                const int i = q.front();
                q.pop();
                if (i == n - 1)
                    return steps;
                seen[i] = true;
                const int u = arr[i];
                if (i + 1 < n)
                    graph[u].push_back(i + 1);
                if (i - 1 >= 0)
                    graph[u].push_back(i - 1);
                for (const int v : graph[u])
                {
                    if (seen[v])
                        continue;
                    q.push(v);
                }
                graph[u].clear();
            }
        }

        throw;
    }
};

int main()
{
}