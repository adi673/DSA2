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

    TreeNode*  DFS(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        
        TreeNode* newNode = new TreeNode(root->val);
        TreeNode* leftList = DFS(root->left);
        TreeNode* rightList = DFS(root->right);

        newNode->right = leftList;

        // Find the end of the left list and connect it to the right list
        TreeNode* current = newNode;
        while (current->right != nullptr) {
            current = current->right;
        }
        current->right = rightList;

        return newNode;


    }

    void flatten(TreeNode* root) {
        TreeNode* newNode=new TreeNode(-1);
        newNode->left= DFS(root)

        return newNode->left;
    }
};
//revise 