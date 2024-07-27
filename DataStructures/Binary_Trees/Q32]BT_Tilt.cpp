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


    int totalTilt = 0;

    // Helper function to calculate sum of tree and tilt
    int sumAndTilt(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int sum_L = sumAndTilt(root->left);
        int sum_R = sumAndTilt(root->right);
        
        int tilt = abs(sum_L - sum_R);
        totalTilt += tilt;
        
        return sum_L + sum_R + root->val;
    }
    
    int findTilt(TreeNode* root) {
        sumAndTilt(root);
        return totalTilt;
    }
};