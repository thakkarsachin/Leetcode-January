/*
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode *ans=new ListNode(),*tmp;
        if(l1==NULL && l2==NULL)
            return NULL;
        tmp = ans;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                ans->val = l1->val;
                l1=l1->next;
            }else{
                ans->val = l2->val;
                l2=l2->next;
            }
            ans->next = new ListNode();
            ans = ans->next;
        }

        while(l1!=NULL){
            ans->val = l1->val;
            ans->next = new ListNode();a
            ans = ans->next;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            ans->val = l2->val;
            ans->next = new ListNode();
            ans = ans->next;
            l2 = l2->next;
        }
        ListNode *tt=tmp;
        while(tt!=NULL && tt->next!=NULL && tt->next->next!=NULL)
            tt=tt->next;
        tt->next=NULL;
        return tmp;
    }
};