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
    vector<int> rightSideView(TreeNode* root) {

        vector<int>out;
        if(root==NULL){
            return out;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();

            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(i==size-1){
                    out.push_back(temp->val);
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }

            }
        }

        return out;
    }
};

// www.leetcode.com/problems/binary-tree-right-side-view/
//we will not use  DFS here . we will use level order traversal because lets say left subtree of root is deeper than right subtree then right vieww will ahve some nodes of left subtree of root node thats why.