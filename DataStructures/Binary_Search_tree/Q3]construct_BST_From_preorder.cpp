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

    TreeNode* construct(TreeNode* root,int node){
        if(root==NULL){
            TreeNode* newNode= new TreeNode(node);
            return newNode;
        }

        if(node<root->val){
            root->left=construct(root->left,node);
            return root;
        }

        if(node>root->val){
            root->right=construct(root->right,node);
            return root;
        }
        return NULL;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=1;
        TreeNode* root=new TreeNode(preorder[0]);
        while(i<preorder.size()){
            root=construct(root,preorder[i]);
            i++;
        }
        return root;
    }
};