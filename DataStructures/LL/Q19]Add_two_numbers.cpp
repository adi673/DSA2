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
        int carry=0;
        int rem=0;
        ListNode* start=new ListNode(-1);
        ListNode* ptr=start;
        
        while(temp1!=NULL || temp2!=NULL || carry){
            int sum=0;
            if(temp1!=NULL){
                sum=sum+temp1->val;
                temp1=temp1->next;
            }

            if(temp2!=NULL){
                sum=sum+temp2->val;
                temp2=temp2->next;
            }
            
            sum=sum+carry;
            ListNode* temp=new ListNode(sum%10);
            carry=sum/10;
            ptr->next=temp;
            ptr=ptr->next;
        }
        return start->next;
    }
};