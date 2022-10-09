/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
Accepted
414,898
Submissions
680,848

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSortedVector( TreeNode* root ){
        if( root == NULL ){
            return {};
        }        
        vector<int> l = findSortedVector(root->left);
        vector<int> r = findSortedVector(root->right);        
        l.push_back(root->val);
        l.insert(l.end(), r.begin(), r.end());
        
        return l;
    }
    
    bool findTarget(TreeNode* root, int target) {
        vector<int> sortedVector = findSortedVector( root );
        int start=0, end=sortedVector.size()-1;
        while( start < end ){
            if( sortedVector[start]+sortedVector[end] < target ){
                start++;
            }
            else if( sortedVector[start]+sortedVector[end] > target ){
                end--;
            }
            else{
                return true;
            }
        }
                return false;
    }
};
int main()
{
}