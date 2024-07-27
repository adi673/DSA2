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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenS=head->next;
        
        if(head->next==NULL){
            return head;
        }
        while(odd->next!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            odd=odd->next;
            //this will handle case when ending node is odd and we kept above even->next!=NULL for even node conditions to avoid run time error
            if(even->next->next!=NULL){
                even->next=even->next->next;
                even=even->next;
            }
            
        }
        
        even->next=NULL;
        odd->next=evenS;

        return head;
    }
};