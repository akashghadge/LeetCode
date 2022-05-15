/*
Given the root of a binary tree, return the sum of values of its deepest leaves.


Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19


Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using max_level approach
class Solution
{
public:
    void help(TreeNode *root, int curr, int *max_level)
    {
        if (!root)
            return;
        *max_level = max(*max_level, curr);
        help(root->left, curr + 1, max_level);
        help(root->right, curr + 1, max_level);
    }
    void dfs(TreeNode *root, int level, int max_level, int *sum)
    {
        if (!root)
            return;
        if (level == max_level)
            *sum = *sum + root->val;
        dfs(root->left, level + 1, max_level, sum);
        dfs(root->right, level + 1, max_level, sum);
    }
    int deepestLeavesSum(TreeNode *root)
    {
        int max_level = 0;
        help(root, 0, &max_level);
        int sum = 0;
        dfs(root, 0, max_level, &sum);
        return sum;
    }
};

// using level order traversal
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> last;
        while (q.size())
        {
            int n = q.size();
            last = {};
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                last.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return accumulate(last.begin(), last.end(), 0);
    }
};
int main()
{
}