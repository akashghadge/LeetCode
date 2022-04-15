/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.



Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []


Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107
Accepted
430,740
Submissions

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
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;
        TreeNode *ans = NULL;
        if (root->val == val)
        {
            return root;
        }
        else if (root->val < val)
        {
            ans = searchBST(root->right, val);
        }
        else
        {
            ans = searchBST(root->left, val);
        }
        return ans;
    }
};
int main()
{
}