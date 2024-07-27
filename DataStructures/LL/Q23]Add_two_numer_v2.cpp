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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
       ListNode* curr=head;
       ListNode* next;

       while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
       } 

       return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverse(l1);
        ListNode* head2=reverse(l2);
        ListNode* temp1=head1;
        ListNode* temp2=head2;
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
            cout<<"value: "<<sum%10<<endl;
            ListNode* temp=new ListNode(sum%10);
            carry=sum/10;
            ptr->next=temp;
            ptr=ptr->next;
        }

        ptr=start;
        start=start->next;
        ptr->next=NULL;
        ptr=reverse(start);
        return ptr;
    }
};