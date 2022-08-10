/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

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
    TreeNode* help(vector<int>&arr,int lo,int hi)
    {
        if(lo>hi || hi>=arr.size() || lo<0)
            return NULL;
        if(lo==hi)
            return new TreeNode(arr[lo]);
        int mid=(lo+hi)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=help(arr,lo,mid-1);
        root->right=help(arr,mid+1,hi);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return help(arr,0,arr.size()-1);
    }
};
int main()
{
}