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

    void findSum(TreeNode* root, int targetSum, vector<int>& in, vector<vector<int>>& out){
        
        if(root->left==NULL && root->right==NULL){
            in.push_back(root->val);
            if(targetSum==root->val){
                out.push_back(in);
            }
            return;
        }

        int val=targetSum-(root->val);
        in.push_back(root->val);
        
        if(root->left!=NULL){
            findSum(root->left,val,in,out);
            in.pop_back();

        }
        
        if(root->right!=NULL){
            findSum(root->right, val, in, out );
            in.pop_back();
        }

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        
        vector<vector<int>> out;
        vector<int> in;
        if(root==NULL){
            return out;
        }
        findSum(root, targetSum, in, out);
        return out;
    }
};