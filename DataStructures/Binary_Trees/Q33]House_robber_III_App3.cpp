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

   pair<int,int> find(TreeNode* root){
        if(root==NULL){
            return {0, 0};
        }

        pair<int,int> left=find(root->left);
        pair<int,int>right=find(root->right);

        int rob_curr=root->val+left.second+right.second;
        int not_rob_curr=max(left.first,left.second)+max(right.first,right.second);
        return{rob_curr, not_rob_curr};
    }

    int rob(TreeNode* root) {
        pair<int,int> result=find(root);
        return max(result.first,result.second);
    }
};

//revise this approach and write it down again in book