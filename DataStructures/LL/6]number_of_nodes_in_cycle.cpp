/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;

        if(head==NULL){
            return NULL;
        }
        
        if(head->next==NULL){
            return NULL;
        }
        
        while(fast!=NULL){
            
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }

            if(fast==slow){
                slow=head;
                break;
            }
        }

        if(fast==NULL){
            return NULL;
        }
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};