/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        if(head->next!=NULL && head->val==head->next->val)
        {
            while(head->next!=NULL && head->val==head->next->val)
            {
                head=head->next;
            }
            return deleteDuplicates(head->next);
        }
        else
        {
            head->next=deleteDuplicates(head->next);
        }
        return head;
    }
};