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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
    pair<int, int> dfs(TreeNode* node, int& count) {
        if (!node) return {0, 0};

        auto left = dfs(node->left, count);
        auto right = dfs(node->right, count);

        int sum = node->val + left.first + right.first;
        int num = 1 + left.second + right.second;
        if (node->val == sum / num) {
            count++;
        }

        return {sum, num};
    }
};

//learn this pair pair approach from House Robber III