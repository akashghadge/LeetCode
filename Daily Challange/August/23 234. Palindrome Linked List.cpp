/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(ListNode *head) {
		//find the middle node
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            slow = slow->next;

		// reverse the last half of the list
        ListNode *dummy = slow;
        ListNode *last = nullptr;
        ListNode *next = nullptr;
        while(dummy){
            next = dummy->next;
            dummy->next = last;
            last = dummy;
            dummy = next;
        }

		// compare each half of the list
        dummy = last;
        while(dummy){
            if (dummy->val == head->val){
                dummy = dummy->next;
                head = head->next;
            } 
            else
                return false;
        }

        return true;
    }
};
int main()
{
}