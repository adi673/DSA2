/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
void DFS(TreeNode* root, vector<int>& result){
    if(root==NULL){
        return;
    }

    DFS(root->left,result);
    result.push_back(root->val);
    DFS(root->right,result);
}
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        vector<int> result;
        DFS(root,result);
        int prev=result[0];
        for(int i=1; i<result.size(); i++){ //don't use for each loop to avoid assigning prev as INT_MIN
            if(result[i]<=prev){ //test case when nodes are equal
                return false;
            }
            prev=result[i];
        }
        return true;
    }

    
};