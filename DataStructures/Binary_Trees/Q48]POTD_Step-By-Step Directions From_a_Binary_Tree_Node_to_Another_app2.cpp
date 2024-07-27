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
private: 
    TreeNode* DFS(TreeNode* root, int p, int q){
        if(root==NULL){
            return NULL;
        }

        if(root->val==p || root->val==q){
            return root;
        }

        TreeNode* left=DFS(root->left, p,q);
        TreeNode* right=DFS(root->right,p,q);

        if(left && right){
            return root;
        }

        if(left!=NULL){
            return left;
        }
        return right;
    }
    bool findPath(TreeNode* root, int value, string& path,int isStarting) {
        if (root == NULL) {
            return false; 
        }
        if (root->val == value) {
            return true; 
        }

        if(isStarting){
            path.push_back('U');
        }else{
            path.push_back('L');
        }
        if (findPath(root->left, value, path, isStarting)) {
            return true;
        }
        path.pop_back();

        if(isStarting){
            path.push_back('U');
        }else{
            path.push_back('R');
        }
        if (findPath(root->right, value, path, isStarting)) {
            return true;
        }
        path.pop_back();
        return false; 
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* Parent=DFS(root, startValue, destValue);
        string StartPath="";
        string destPath="";

        findPath(Parent, startValue, StartPath,1);
        findPath(Parent, destValue, destPath,0);

        StartPath+=destPath;
        return StartPath;
    }
};

// lowest common ancestor method
//this is derived question from Q27