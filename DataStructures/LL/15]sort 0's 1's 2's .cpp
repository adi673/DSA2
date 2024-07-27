class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if (!head || !head->next) return head; // Edge case for empty list or single node list
        
        Node* zero = new Node(-1); // Dummy node for zero list
        Node* one = new Node(-1);  // Dummy node for one list
        Node* two = new Node(-1);  // Dummy node for two list
        
        Node* zero_tail = zero; // Tail pointer for zero list
        Node* one_tail = one;   // Tail pointer for one list
        Node* two_tail = two;   // Tail pointer for two list
        
        Node* temp = head; // Temporary pointer to traverse the list
        
        // Traverse the list and distribute nodes into zero, one, and two lists
        while (temp != NULL) {
            if (temp->data == 0) {
                zero_tail->next = temp;
                zero_tail = zero_tail->next;
            } else if (temp->data == 1) {
                one_tail->next = temp;
                one_tail = one_tail->next;
            } else if (temp->data == 2) {
                two_tail->next = temp;
                two_tail = two_tail->next;
            }
            temp = temp->next;
        }
        
        // Connect the three lists
        // Connect the three lists
        if (one->next) {
            zero_tail->next = one->next;
        } else {
            zero_tail->next = two->next;
        }
        
        one_tail->next = two->next;
        two_tail->next = NULL; // Important to terminate the list
        
        // Set the new head of the sorted list
        if (zero->next) {
            head = zero->next;
        } else if (one->next) {
            head = one->next;
        } else {
            head = two->next;
        }
        
        
        // Clean up dummy nodes
        delete zero;
        delete one;
        delete two;
        
        return head;
    }
};