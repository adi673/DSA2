/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insertdata(TreeNode* root, stack<int>& st){
        if(root==NULL ){
            return;
        }
        insertdata(root->right, st);
        st.push(root->val);
        insertdata(root->left, st);
        return;
    }

    TreeNode* increasingBST(TreeNode* root) {
        stack<int> st;
        insertdata(root, st);
        
        if (st.empty()) {
            return nullptr; // Return nullptr if the stack is empty
        }

        // Create the tree using the stack elements
        TreeNode* head = new TreeNode(st.top());
        st.pop();
        TreeNode* ptr = head;
        while (!st.empty()) {
            TreeNode* temp = new TreeNode(st.top());
            st.pop();
            ptr->right = temp;
            ptr = temp;
        }
        return head;
    
    }
    
};