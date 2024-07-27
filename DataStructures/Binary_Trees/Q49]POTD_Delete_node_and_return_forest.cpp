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
    TreeNode* dfs(TreeNode* root, const unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (root == nullptr) {
            return nullptr;
        }
        
        root->left = dfs(root->left, to_delete_set, forest);
        root->right = dfs(root->right, to_delete_set, forest);
        
        if (to_delete_set.find(root->val) != to_delete_set.end()) {
            if (root->left) {
                forest.push_back(root->left);
            }
            if (root->right) {
                forest.push_back(root->right);
            }
            delete root; // delete the node
            return nullptr; // return nullptr to parent
        }
        
        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        if (root && to_delete_set.find(root->val) == to_delete_set.end()) {
            forest.push_back(root);
        }
        
        dfs(root, to_delete_set, forest);
        return forest;
    }
};
//revise 2x
