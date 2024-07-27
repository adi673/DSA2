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

    pair<int,int>helpBalanced(TreeNode* root) {
        if(root==NULL){
            return {true,0};
        }
        pair<int,int> left=helpBalanced(root->left);
        pair<int,int> right=helpBalanced(root->right);

        bool bal=left.first && right.first;

        bal=bal && (abs(left.second-right.second)<=1);

        int height=1+max(left.second,right.second);

        return {bal,height};
    }

    bool isBalanced(TreeNode* root) {
        pair<int,int> result=helpBalanced(root);

        return result.first;
        
    }
};