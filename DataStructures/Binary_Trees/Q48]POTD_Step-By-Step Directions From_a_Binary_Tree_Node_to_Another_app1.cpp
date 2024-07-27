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
    bool findPath(TreeNode* root, int value, string& path) {
        if (root == NULL) {
            return false; 
        }
        if (root->val == value) {
            return true; 
        }

        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();

        return false; 
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";
        
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }

        // Steps to go up from startValue to the common ancestor
        string result(startPath.size() - i, 'U');
        // Steps to go down from the common ancestor to destValue
        result += destPath.substr(i);
        
        return result;  
    }
};

// Find the path strings from root → s, and root → t. Can you use these two strings to prepare the final answer?
// Remove the longest common prefix of the two path strings to get the path LCA → s, and LCA → t. Each step in the path of LCA → s should be reversed as 'U'.