/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.



Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination:
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination:
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"


Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef vector<vector<int>> vii;
    typedef vector<int> vi;
    struct Node
    {
        int id;
        char ch;
        Node(int id, char ch)
        {
            this->id = id;
            this->ch = ch;
        }
    };
    void dfs(vii &graph, int src, vi &visited, vi &curr)
    {
        if (visited[src])
            return;
        curr.push_back(src);
        visited[src] = true;
        for (auto nbr : graph[src])
        {
            if (visited[nbr])
                continue;
            dfs(graph, nbr, visited, curr);
        }
    }
    vii comps(vii graph, int n)
    {
        vector<int> visited(n, 0);
        vii ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> curr;
            if (visited[i])
                continue;
            dfs(graph, i, visited, curr);
            ans.push_back(curr);
        }
        return ans;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        vii graph(n);
        for (auto val : pairs)
        {
            graph[val[0]].push_back(val[1]);
            graph[val[1]].push_back(val[0]);
        }
        vii conn = comps(graph, n);
        for (auto curr : conn)
        {
            vector<Node *> sorted;
            vector<Node *> sorted_id;
            for (auto val : curr)
            {
                sorted.push_back(new Node(val, s[val]));
                sorted_id.push_back(new Node(val, s[val]));
            }
            sort(sorted.begin(), sorted.end(), [](Node *f, Node *s)
                 { return f->ch < s->ch; });
            sort(sorted_id.begin(), sorted_id.end(), [](Node *f, Node *s)
                 { return f->id < s->id; });
            for (int i = 0; i < sorted_id.size(); i++)
            {
                s[sorted_id[i]->id] = sorted[i]->ch;
            }
        }
        return s;
    }
};
int main()
{
}