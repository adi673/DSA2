class Solution
{
    public:
    int recurAdd(Node* head) {
        if(head->next==NULL){
            if(head->data==9){
                head->data=0;
                return 1;
            }else{
                head->data=head->data+1;
                return 0;
            }
        }
        int val=recurAdd(head->next);
        head->data=head->data+val;
        if(head->data==10){
            head->data=0;
            return 1;
        }else{
            return 0;
        }
    }
    
    Node* addOne(Node *head) 
    {
       int val=recurAdd(head);
       if(val==1){
           Node* temp=new Node(1);
           temp->next=head;
           head=temp;
       }
        return head;
    }
};