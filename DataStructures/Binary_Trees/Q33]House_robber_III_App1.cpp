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
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        int alt1=0;
        int alt2=0;
        q.push(root);
        bool invert=true;
        while(!q.empty()){
            int size=q.size();

            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(invert){
                    alt1=alt1+temp->val;
                }else{
                    alt2=alt2+temp->val;
                }
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            invert=(!invert);
        }
        return max(alt1,alt2);
    }
};




//this method fails in some cases where we can choose to not pick two consecutive node and pick up the third node where we could get max loot 
//eg input: [4,1,null,2,null,3]

//here actual answer is when we pick 4 and 3. for that we have to use recursive approach.
//recursive apporach: 
// so in  recursion we will consider factor last one was picked or not. if last one was picked then we will not pick current and give call  for 
//left and right. and if last one was not pick then we will pick current also and not pick it also and will give left right call for both