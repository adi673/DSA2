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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return false;
        }



        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next==NULL){
                return false;
            }
            fast=fast->next;
            if(fast==slow){
                slow=head;
                return true;
                
            }
        }
      
        return false;
        
    }
};