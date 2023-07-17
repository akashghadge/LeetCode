/*
        445. Add Two Numbers II
        

        You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 
Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]


Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]


Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]


 
Constraints:


	The number of nodes in each linked list is in the range [1, 100].
	0 <= Node.val <= 9
	It is guaranteed that the list represents a number that does not have leading zeros.


 
Follow up: Could you solve it without reversing the input lists?
        */
        

        #include <bits/stdc++.h>
        using namespace std;
        class Solution {public:    ListNode* rev(ListNode* l1)    {        ListNode* curr=l1;        ListNode* prev=NULL;        while(curr)        {            ListNode* next=curr->next;            curr->next=prev;            prev=curr;            curr=next;           }        return prev;    }    int cn(ListNode* l)    {        int n=0;        while(l)        {            l=l->next;            n++;        }        return n;    }    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        l1=rev(l1);        l2=rev(l2);        int n=cn(l1);        int m=cn(l2);        if(m>n)            swap(l1,l2);        int carry=0;        ListNode* t1=l1,*t2=l2,* prev_t1=NULL;        while(t1 and t2)        {            int sum=t1->val+t2->val+carry;            t1->val=sum%10;            carry=sum/10;            prev_t1=t1;            t1=t1->next;            t2=t2->next;        }        while(t1)        {            t1->val+=carry;            carry=t1->val/10;            t1->val%=10;            prev_t1=t1;            t1=t1->next;        }        if(carry!=0)        {            prev_t1->next=new ListNode(carry);        }        l1=rev(l1);        return l1;    }};
