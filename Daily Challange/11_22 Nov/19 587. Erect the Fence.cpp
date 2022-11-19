/*
You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.

 

Example 1:


Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
Example 2:


Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.
 

Constraints:

1 <= trees.length <= 3000
trees[i].length == 2
0 <= xi, yi <= 100
All the given positions are unique.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> points;
        
        sort(trees.begin(), trees.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        int n = trees.size();
        
        for (int i = 0; i < n; ++i) {
            while (points.size() >= 2 
                   && orientation(points[points.size() - 2], points[points.size() - 1], trees[i]) > 0) {
                points.pop_back();
            }
            
            points.push_back(trees[i]);
        }
        
        points.pop_back();
        for (int i = n - 1; i >= 0; --i) {
            while (points.size() >= 2 
                   && orientation(points[points.size() - 2], points[points.size() - 1], trees[i]) > 0) {
                points.pop_back();
            }
            
            points.push_back(trees[i]);
        }
        
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        
        for (auto& p : points) {
            if (ans.size() > 0 && p == ans.back()) {
                continue;
            }
            
            ans.push_back(p);
        }
        
        return ans;
    }
    
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - p[0]) - (r[1] - p[1]) * (q[0] - p[0]);
    }
};
int main()
{
}