/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    
bool isValidBSTUtil(TreeNode* root, long long int min_val, long long int max_val) {
    if (root == NULL){
        return true;
}
    if (root->val <= min_val || root->val >= max_val){
        return false;
    }
    // For left subtree, the maximum value should be the current node's value
    // For right subtree, the minimum value should be the current node's value
    return isValidBSTUtil(root->left, min_val, root->val) && isValidBSTUtil(root->right, root->val, max_val);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

    
};