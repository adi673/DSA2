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

    

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        queue<TreeNode*> q;
        q.push(root);
        stack<int> st;
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(lvl%2!=0){
                    cout<<"putting value :"<<st.top()<<" for  "<<temp->val<<endl;
                    temp->val=st.top();
                    st.pop();
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                    if(lvl%2==0){
                        st.push(temp->left->val);
                    }
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                    if(lvl%2==0){
                        st.push(temp->right->val);
                    }
                }
            }
            lvl++;
        }
        return root;
    }
};
//BFS
//imp question. revise 2x
//here on even level we are storing left and root values of nodes popped from queue in stack aand on odd levels we are popping from stack and putting in the tree.