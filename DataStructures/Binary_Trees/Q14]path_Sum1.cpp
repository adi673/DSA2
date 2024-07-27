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

    bool findSum(TreeNode* root, int targetSum){
        if(root->left==NULL && root->right==NULL){
            int val=targetSum-(root->val);
            if(val==0){
                return true;
            }else{
                return false;
            }
        }
        int val=targetSum-(root->val);
        bool lef;
        if(root->left!=NULL){
            lef=findSum(root->left,val);
        }
        bool righ;
        if(root->right!=NULL){
            righ=findSum(root->right, val );
        }

        
        if(lef || righ ){
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        return findSum(root, targetSum);
    }
};