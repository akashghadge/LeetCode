/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    struct comp
    {
        bool operator()(ListNode *f, ListNode *s)
        {
            if (!f || !s)
                return true;
            return f->val > s->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(0);
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;
        for (auto val : lists)
            if (val)
                pq.push(val);
        ListNode *temp = dummy;
        while (pq.size())
        {
            ListNode *curr = pq.top();
            pq.pop();
            if (!curr)
                break;
            if (curr->next)
                pq.push(curr->next);
            temp->next = curr;
            temp = temp->next;
        }
        return dummy->next;
    }
};
int main()
{
}