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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* temp=new ListNode(-1);
        ListNode* start= temp;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* next1;
        ListNode* next2;
        while(temp1!=NULL && temp2!=NULL){
           if(temp1->val==temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;               
            }else if(temp1->val>temp2->val){
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
            }else{
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
            }
        }
        if(temp1==NULL){
            temp->next=temp2;
        }else{
            temp->next=temp1;
        }
        return start->next;
    }

    ListNode* findMiddle(ListNode* head) {
        if (!head) return head;
    
        ListNode* slow = head;
        ListNode* fast = head;
    
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        return slow;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) return head;
    
        ListNode* middle = findMiddle(head);
        ListNode* nextToMiddle = middle->next;
        middle->next = NULL;
    
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(nextToMiddle);
    
        return mergeTwoLists(left, right);
    }   

    ListNode* sortList(ListNode* head) {
        head = mergeSort(head);
        return head;
    }
};