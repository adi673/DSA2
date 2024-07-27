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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2; //if roo1 and root2 null honge to null hi return hoga and lets say roo1 null hai and root2 nhi hai to poori subtree root2 ki return ho jayegi
        if (!root2) return root1;
        
        // Merge the current nodes
        TreeNode* mergedRoot = new TreeNode(root1->val + root2->val);
        
        // Recursively merge left subtrees
        mergedRoot->left = mergeTrees(root1->left, root2->left);
        
        // Recursively merge right subtrees
        mergedRoot->right = mergeTrees(root1->right, root2->right);
        
        return mergedRoot;
    }
};
//https://leetcode.com/problems/merge-two-binary-trees/