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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        
        if(root==NULL){
            return out;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool LR=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> in;
            for(int i=0; i<size; i++){
                TreeNode* top=q.front();
                q.pop();
                in.push_back(top->val);
                
                if(top->left!=NULL){
                    q.push(top->left);
                }

                if(top->right!=NULL){
                    q.push(top->right);
                }
                
                
            }
            if(!LR){
                reverse(in.begin(), in.end());
            }
            out.push_back(in);
            LR= !LR;
        }

        return out;
    }
};

// www.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/