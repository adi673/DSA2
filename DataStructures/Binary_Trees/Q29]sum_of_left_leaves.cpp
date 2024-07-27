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

    void sumLeft(TreeNode* root, int flag, vector<int>& out){
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL && flag==1){
            out.push_back(root->val);
            return;
        }

        

        sumLeft(root->left,1,out);
        sumLeft(root->right,0,out);
        return;
    }

    int sumOfLeftLeaves(TreeNode* root) {

        if(root->left==NULL && root->right==NULL){
            return 0;
        }

        vector<int>out;
        sumLeft(root, -1, out);

        int i=0;
        int result=0;
        while(i<out.size()){
            result=result+out[i];
            i++;
        }
        return result;
    }
};
// www.leetcode.com/problems/sum-of-left-leaves/
//search for any optimal implementation on chatgpt