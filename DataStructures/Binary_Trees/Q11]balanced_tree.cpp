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

    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {

        if(root==NULL){
            return true;
        }

        int left=maxDepth(root->left);
        int right=maxDepth(root->right);

        int val=abs(left-right);

        if(val>1){
            return false;
        }

        return (isBalanced(root->left) && isBalanced(root->right));


        //imp case --> agar kioi node hame balance dikh raha hai upar se usaki left and right max hight leke to usake left and right node balance hai kya check karo.
        // if(val<2 && val>-2){
        //     return (isBalanced(root->left) && isBalanced(root->right));
        // }
        // return false;
        
    }
};
//Revise it again

//check strivers solution also. it is kind of similar  https://youtu.be/Yt50Jfbd8Po