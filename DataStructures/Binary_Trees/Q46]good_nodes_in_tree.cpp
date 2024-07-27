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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }
        
        int good = 0;
        if (node->val >= maxVal) {
            good = 1;
            maxVal = node->val;
        }
        
        good += dfs(node->left, maxVal);
        good += dfs(node->right, maxVal);
        
        return good;
    }
};

//revise 2x
//https://leetcode.com/problems/count-good-nodes-in-binary-tree/