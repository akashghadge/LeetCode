/*
        863. All Nodes Distance K in Binary Tree


        Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


Example 2:

Input: root = [1], target = 1, k = 3
Output: []



Constraints:


        The number of nodes in the tree is in the range [1, 500].
        0 <= Node.val <= 500
        All the values Node.val are unique.
        target is the value of one of the nodes in the tree.
        0 <= k <= 1000
        */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
        vector<int> ans;
        map<TreeNode *, TreeNode *> parent; // son=>parent
        set<TreeNode *> visit;              // record visied node
        void findParent(TreeNode *node)
        {
                if (!node)
                        return;
                if (node->left)
                {
                        parent[node->left] = node;
                        findParent(node->left);
                }
                if (node->right)
                {
                        parent[node->right] = node;
                        findParent(node->right);
                }
        }
        vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
        {
                if (!root)
                        return {};
                findParent(root);
                dfs(target, K);
                return ans;
        }
        void dfs(TreeNode *node, int K)
        {
                if (visit.find(node) != visit.end())
                        return;
                visit.insert(node);
                if (K == 0)
                {
                        ans.push_back(node->val);
                        return;
                }
                if (node->left)
                {
                        dfs(node->left, K - 1);
                }
                if (node->right)
                {
                        dfs(node->right, K - 1);
                }
                TreeNode *p = parent[node];
                if (p)
                        dfs(p, K - 1);
        }
};
