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
            cout<<"returned here"<<endl;
            return NULL;
        }

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            if(temp1==NULL){
                temp1=headB;
            }else{
                temp1=temp1->next;
            }
            
            if(temp2==NULL){
                temp2=headA;
            }else{
                temp2=temp2->next;
            }

        }
        
        return temp1;
        
        

    }
};

// Time Complexity: O(2*max(length of list1,length of list2))
// Reason: Uses the same concept of the difference of lengths of two lists.

// Space Complexity: O(1)
// Reason: No extra data structure is used

//Approach:
// 
// The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
// 
// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.