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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(root==NULL){
            return pre;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            pre.push_back(temp->val);

            //imp statement here u have to push right first and then left becuase pre order left al must be print first. so left will be on top of right in stack
            if(temp->right!=NULL){
                st.push(temp->right);
            }
            if(temp->left!=NULL){
                st.push(temp->left);
            }
        }
        
        return pre;
    }
};