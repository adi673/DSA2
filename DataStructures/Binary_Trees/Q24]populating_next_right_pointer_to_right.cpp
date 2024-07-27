/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        connectNodes(root->left, root->right);
        return root;
    }
    
    void connectNodes(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr)
            return;
        
        // Connect the current nodes
        node1->next = node2;
        
        // Recur for the left and right subtrees
        connectNodes(node1->left, node1->right);
        connectNodes(node2->left, node2->right);
        
        // Connect across the subtrees
        connectNodes(node1->right, node2->left);
    }
};

//revise it again x1