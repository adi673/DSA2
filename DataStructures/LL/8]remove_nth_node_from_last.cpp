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
        if(head==NULL){
            return NULL;
        }

        if(head->next==NULL&&n==1){
            return NULL;
        }

        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }

        int val=count-n+1;

        //first Node deletion 
        ListNode* temp2=head;
        if(val==1){
            head=head->next;
            temp2->next=NULL;
            return head;
        }

        //nodes other than first node
        int counter=1;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(counter!=val){
            prev=curr;
            cout<<curr->val<<endl;
            curr=curr->next;
            counter++;
        }      
        prev->next=curr->next;
        curr->next=NULL;
        return head;
    }
};