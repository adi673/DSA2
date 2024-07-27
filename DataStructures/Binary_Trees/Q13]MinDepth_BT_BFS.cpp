//https://youtu.be/tZS4VHtbYoo?t=509

//optimal approach using level order traversal


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
    int minDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }
        
        int depth=1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL){
                    return depth;
                }
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                
            }
            depth++;
        }
        return depth;
    }
};