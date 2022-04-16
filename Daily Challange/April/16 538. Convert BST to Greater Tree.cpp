/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]


Constraints:

The number of nodes in the tree is in the range [0, 104].
-104 <= Node.val <= 104
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.


Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/


*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int cur_sum = 0;

public:
    void travel(TreeNode *root)
    {
        if (!root)
            return;
        if (root->right)
            travel(root->right);

        root->val = (cur_sum += root->val);
        if (root->left)
            travel(root->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        travel(root);
        return root;
    }
};

int main()
{
}