/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* DFS(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }

        if(root==p || root==q){
            return root;
        }

        TreeNode* left=DFS(root->left, p,q);
        TreeNode* right=DFS(root->right,p,q);

        if(left && right){
            return root;
        }

        if(left!=NULL){
            return left;
        }
        return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root, p,q);
    }
};

//revise x2

// Approach
// Recursive Approach: Use a depth-first search (DFS) to explore the tree.
// Base Case: If the current node is null, return null. If the current node is either p or q, return the current node.
// Recur for Left and Right Subtrees: Recursively find the LCA in the left and right subtrees.
// Combine Results:
// If both the left and right recursive calls return non-null values, it means p and q are found in different subtrees. Thus, the current node is the LCA.
// If only one of the recursive calls returns a non-null value, it means both p and q are in the same subtree. Hence, return the non-null result.
// If both are null, return null.