/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.



Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104


*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> curr, next;
        unordered_map<TreeNode *, TreeNode *> par;
        unordered_map<TreeNode *, int> mp;
        int total = 0;
        curr.push(root);
        int ptr = 0;
        while (curr.size() and ptr < 2)
        {
            mp.clear();
            par.clear();
            total = 0;
            while (curr.size())
            {
                auto node = curr.front();
                curr.pop();
                node->val = 0;
                if (node->left)
                {
                    par[node->left] = node;
                    mp[node] += node->left->val;
                    total += node->left->val;
                    next.push(node->left);
                }
                if (node->right)
                {
                    par[node->right] = node;
                    mp[node] += node->right->val;
                    total += node->right->val;
                    next.push(node->right);
                }
            }
            curr = next;
            next = queue<TreeNode *>();
            ptr++;
        }
        while (curr.size())
        {
            int next_total = 0;
            while (curr.size())
            {
                auto node = curr.front();
                curr.pop();
                node->val = total - mp[par[node]];
                if (node->left)
                {
                    par[node->left] = node;
                    mp[node] += node->left->val;
                    next_total += node->left->val;
                    next.push(node->left);
                }
                if (node->right)
                {
                    par[node->right] = node;
                    mp[node] += node->right->val;
                    next_total += node->right->val;
                    next.push(node->right);
                }
            }
            curr = next;
            next = queue<TreeNode *>();
            total = next_total;
        }
        return root;
    }
};
int main()
{
}