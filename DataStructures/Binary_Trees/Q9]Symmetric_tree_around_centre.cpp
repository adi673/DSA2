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

    bool find(TreeNode* p, TreeNode* q){
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q==NULL){
            return true;
        }
        if(p->val != q->val){
            return false;
        }
        return(find(p->left,q->right) && find(p->right,q->left));
    }

    bool isSymmetric(TreeNode* root) {
        return find(root->left, root->right);
    }
};

//leetcode.com/