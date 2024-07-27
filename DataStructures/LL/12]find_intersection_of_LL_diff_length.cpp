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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA==NULL || headB==NULL){
            return NULL;
        }

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int count=0;
        while(temp1!=NULL && temp2!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1!=NULL){
            while(temp1!=NULL){
                count++;
                temp1=temp1->next;
            }
            temp1=headA;
            temp2=headB;
            while(count!=0){
                temp1=temp1->next;
                count--;
            }
            
        }else{
            while(temp2!=NULL){
                count++;
                temp2=temp2->next;
            }
            temp1=headA;
            temp2=headB;
            while(count!=0){
                temp2=temp2->next;
                count--;
            }
        }

        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;

    }
};


// Time Complexity:
// O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.

// Space Complexity: O(1)
// Reason: No extra space is used.