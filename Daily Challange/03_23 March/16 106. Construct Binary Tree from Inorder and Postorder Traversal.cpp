/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inToIndex;

        for (int i = 0; i < inorder.size(); ++i)
            inToIndex[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1, inToIndex);
    }

private:
    TreeNode *build(const vector<int> &inorder, int inStart, int inEnd,
                    const vector<int> &postorder, int postStart, int postEnd,
                    const unordered_map<int, int> &inToIndex)
    {
        if (inStart > inEnd)
            return nullptr;

        const int rootVal = postorder[postEnd];
        const int rootInIndex = inToIndex.at(rootVal);
        const int leftSize = rootInIndex - inStart;

        TreeNode *root = new TreeNode(rootVal);
        root->left = build(inorder, inStart, rootInIndex - 1, postorder, postStart,
                           postStart + leftSize - 1, inToIndex);
        root->right = build(inorder, rootInIndex + 1, inEnd, postorder,
                            postStart + leftSize, postEnd - 1, inToIndex);
        return root;
    }
};

int main()
{
}