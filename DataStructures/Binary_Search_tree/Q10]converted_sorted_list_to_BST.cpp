class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        return sortedListToBSTRec(head, nullptr);
    }

private:
    TreeNode* sortedListToBSTRec(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBSTRec(head, slow);
        root->right = sortedListToBSTRec(slow->next, tail);
        
        return root;
    }
};

//revise x2