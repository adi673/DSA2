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
        
        //TreeNode* newNode = new TreeNode(root->val);
        TreeNode* leftList = DFS(root->left);
        TreeNode* rightList = DFS(root->right);

        if(leftList){
            root->right = leftList;
            TreeNode* current = leftList;
            while (current->right != nullptr) {
                current = current->right;
            }
            current->right = rightList;
            root->left=NULL;
        }else{
            root->right=rightList;
        }
        return root;

    }

    void flatten(TreeNode* root) {       
        DFS(root);
    };
};

//revise;