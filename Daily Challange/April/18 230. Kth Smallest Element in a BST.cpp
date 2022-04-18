/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104


Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?


*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countM = 0;
    int kUtil(TreeNode *root, vector<int> &ans, int k)
    {
        if (root == NULL)
        {
            return 0;
        }
        kUtil(root->left, ans, k);
        if (countM <= k)
        {
            ans.push_back(root->val);
        }
        else
        {
            return 0;
        }
        kUtil(root->right, ans, k);
        return 0;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        kUtil(root, ans, k);
        return ans[k - 1];
    }
};
int main()
{
}