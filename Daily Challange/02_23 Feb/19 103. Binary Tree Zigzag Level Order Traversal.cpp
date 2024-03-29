/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        bool rev=0;
        while(q.size() or next.size())
        {
            vector<int> res;
            while(q.size())
            {
                auto curr=q.front();
                q.pop();
                res.push_back(curr->val);
                if(curr->left)
                    next.push(curr->left);
                if(curr->right)
                    next.push(curr->right);
            }
            if(rev)
                reverse(res.begin(),res.end());
            ans.push_back(res);
            queue<TreeNode*> temp=next;
            next=q;
            q=temp;
            rev=!rev;
        }
        return ans;
    }
};
int main()
{
}