class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
       struct Node* head = *head_ref;
        struct Node* temp = head;
        struct Node* curr;
       while (temp != NULL) {
            if (temp->data == x) {
                curr = temp;
                temp = temp->next;

                if (curr == head) {
                    head = temp;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                    *head_ref = head;
                } else {
                    curr->prev->next = temp;
                    if (temp != NULL) {
                        temp->prev = curr->prev;
                    }
                }

                free(curr);
            } else {
                temp = temp->next;
            }
        }
       return ;
    }
};