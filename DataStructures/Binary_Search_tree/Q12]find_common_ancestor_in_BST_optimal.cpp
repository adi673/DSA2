/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        if(p->val<root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right, p,q);
        }

        //condition when one of the val equal to root or oneis greater than root and another is smaller than root and ll other leftut condition that particualr node will be root only
        return root;
    }
};