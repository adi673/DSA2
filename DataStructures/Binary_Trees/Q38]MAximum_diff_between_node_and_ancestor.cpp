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

    pair<int,int> find(TreeNode* root){
        if (root == nullptr) {
            return {INT_MAX, INT_MIN};
        }
        
        pair<int, int> left = find(root->left);
        pair<int, int> right = find(root->right);
        
        int min_val = min({left.first, right.first, root->val});
        int max_val = max({left.second, right.second, root->val});
        
        return {min_val, max_val};
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        pair<int, int> pr = find(root);
        int diff = max(abs(pr.first - root->val), abs(pr.second - root->val));
        
        int left_diff = maxAncestorDiff(root->left);
        int right_diff = maxAncestorDiff(root->right);
        
        return max({diff, left_diff, right_diff});
      
    }
};

//revise
///didn't got why we callling maxAncestor fxn recursivel.
// uppder diff function is just doing DFS and storing smallest and greatest variable 