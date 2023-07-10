/*
        111. Minimum Depth of Binary Tree
        

        Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 2


Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5


 
Constraints:


	The number of nodes in the tree is in the range [0, 105].
	-1000 <= Node.val <= 1000
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
class Solution {
public:
    void dfs(TreeNode*root,int curr,int *mn)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            *mn=min(*mn,curr);
        }
        dfs(root->left,curr+1,mn);
        dfs(root->right,curr+1,mn);
    }
    int minDepth(TreeNode* root) {
        int mn=INT_MAX;
        if(!root) return 0;
        dfs(root,1,&mn);
        return mn;
    }
};
