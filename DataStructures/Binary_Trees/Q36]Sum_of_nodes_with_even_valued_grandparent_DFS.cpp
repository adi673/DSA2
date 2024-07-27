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

    int dfs(TreeNode* node, TreeNode* parent, TreeNode* Grandparent){
        if(node==NULL){
            return 0;
        }

        int sum=0;
        if(Grandparent && Grandparent->val%2==0){
            sum=sum+node->val;
        }

        sum+=dfs(node->left,node,parent);
        sum+=dfs(node->right,node,parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
       return dfs(root,NULL,NULL);
    }
};

//using DFS 
//revise this approach once
