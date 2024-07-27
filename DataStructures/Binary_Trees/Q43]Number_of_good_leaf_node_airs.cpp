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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* root, int distance, int& count) {
        if (!root) return {};
        if (!root->left && !root->right) return {0}; // Leaf node
        
        vector<int> left = dfs(root->left, distance, count);
        vector<int> right = dfs(root->right, distance, count);
        
        for (int l : left) {
            for (int r : right) {
                if (l + r + 2 <= distance) count++;
            }
        }
        
        vector<int> current;
        for (int l : left) {
            if (l + 1 < distance) current.push_back(l + 1);
        }
        for (int r : right) {
            if (r + 1 < distance) current.push_back(r + 1);
        }
        return current;
    }
};
//didn't get it . 
//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/discuss/755788/C%2B%2B-DFS-solution-with-explanation
//revise it agian 4x
//chatgpt solutn