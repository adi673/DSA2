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
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return recover(traversal, index, 0);
    }

private:
    TreeNode* recover(const string& traversal, int& index, int depth) {
        int currentDepth = 0;

        // Calculate the depth by counting dashes
        while (index + currentDepth < traversal.size() && traversal[index + currentDepth] == '-') {
            currentDepth++;
        }

        // If the current depth does not match the required depth, return null
        if (currentDepth != depth) return nullptr;

        index += currentDepth;

        // Read the next number (node value)
        int value = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(value);

        // Recursively recover the left and right children
        node->left = recover(traversal, index, depth + 1);
        node->right = recover(traversal, index, depth + 1);

        return node;
    }

};

//not done by me revise 2x. done by chatgpt
//https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/