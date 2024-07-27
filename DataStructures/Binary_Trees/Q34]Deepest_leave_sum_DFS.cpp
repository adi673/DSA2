#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0;
        int sum = 0;
        dfs(root, 0, maxDepth, sum);
        return sum;
    }


    void dfs(TreeNode* node, int currentDepth, int& maxDepth, int& sum) {
        if (!node) return;
        
        if (!node->left && !node->right) {  // Leaf node
            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
                sum = node->val;  // Start a new sum
            } else if (currentDepth == maxDepth) {
                sum += node->val;  // Add to the existing sum
            }
        } else {
            dfs(node->left, currentDepth + 1, maxDepth, sum);
            dfs(node->right, currentDepth + 1, maxDepth, sum);
        }
    }
};
//revise
//using DFS
