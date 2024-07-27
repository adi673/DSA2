class Solution
{
    public:
    
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
       head = reverse(head);
        
        Node* temp = head;
        int carry = 1;  // We need to add one, so initialize carry to 1
        
        while (temp != NULL) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            if (carry == 0) {
                break;  // No need to continue if there is no carry
            }
            if (temp->next == NULL && carry > 0) {
                temp->next = new Node(carry);
                break;
            }
            temp = temp->next;
        }
        
        // Reverse the linked list back to its original order
        head = reverse(head);
        
        return head;
        
    }
};