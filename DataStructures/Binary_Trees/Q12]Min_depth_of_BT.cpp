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
    int minDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }

        if(root->left!=NULL && root->right==NULL){
            return minDepth(root->left)+1;
            
        }

        if(root->right!=NULL && root->left==NULL){
            return minDepth(root->right)+1;
        }
        
        int left=minDepth(root->left);
        int right=minDepth(root->right);

        return min(left,right)+1;
    }
};

//revise
//This is brute force approach as we are going till each leaf node and then returning the min depth inshort we are using depth first search.
// to find optimal solution we can use breadth first search and return the depth of the first leaf node we encounter.
//imp test case [2,null,3,null,4,null,5,null,6]