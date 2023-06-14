/*
        530. Minimum Absolute Difference in BST


        Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.


Example 1:

Input: root = [4,2,6,1,3]
Output: 1


Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1



Constraints:


        The number of nodes in the tree is in the range [2, 104].
        0 <= Node.val <= 105



Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
        */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
        void help(TreeNode *root, int *prev, int *mn)
        {
                if (!root)
                        return;
                help(root->left, prev, mn);
                if (*prev != -1)
                {
                        *mn = min(*mn, abs(root->val - (*prev)));
                }
                *prev = root->val;
                help(root->right, prev, mn);
        }
        int getMinimumDifference(TreeNode *root)
        {
                int prev = -1;
                int ans = INT_MAX;
                help(root, &prev, &ans);
                return ans;
        }
};
