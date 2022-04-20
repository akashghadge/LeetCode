/*

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

class BSTIterator
{
public:
    vector<int> res;
    int ptr = 0;
    int size = 0;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode *root)
    {
        dfs(root);
        this->size = res.size();
    }

    int next()
    {
        if (!hasNext())
            return -1;
        return res[ptr++];
    }

    bool hasNext()
    {
        if (ptr < size)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// ideal solutions
class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);

        return top->val;
    }

    /** put all the left child() of root */
    void find_left(TreeNode *root)
    {
        TreeNode *p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

int main()
{
}