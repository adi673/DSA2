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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry;
        int rem=0;
        ListNode* start=new ListNode(-1);
        ListNode* ptr=start;
        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL && temp2!=NULL){
                int val=temp1->data + temp2->data+rem;
            }else if(temp1==NULL){
                int val=temp2->data+rem;
            }else if(temp2==NULL){
                int val=temp1->data+rem;
            }
            
            ListNode* temp;
            if(temp1->next==NULL && temp2->next==NULL){
                if(val>9){
                    rem=val%10;
                    val=val/10;
                    temp=new ListNode(val);
                    ptr->next=temp;
                    ptr=temp;
                }else{
                    temp=new ListNode(val);
                    ptr->next=temp;
                    ptr=temp;
                }
            }else{
                if(val>9){
                    rem=val%10;
                    val=val/10;
                    temp=new ListNode(rem);
                    ptr->next=temp;
                    ptr=temp;
                }else{
                    temp=new ListNode(val);
                    ptr->next=temp;
                    ptr=temp;
                }
            }
        }
        return start->next;
    }
};

//NOT workinf