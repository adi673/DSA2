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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //edge case
        if(head==NULL){
            return NULL;
        }
        //edge case
        if(head->next==NULL&&n==1){
            return NULL;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0; i<n; i++){
            fast=fast->next;
        }

        //condition for firstNode , edge case
        
        if(fast==NULL){
            head=head->next;
            slow->next==NULL;
            return head;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* temp=slow->next;
        slow->next=temp->next;
        temp->next=NULL;

        return head;
    }
};