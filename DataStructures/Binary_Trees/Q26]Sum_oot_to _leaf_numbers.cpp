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

    void DFS(TreeNode* root, vector<int>& out,int n){

        //imp case. if we do pushing final value of n when root==NULL then that values might get pushed two times if it is leaff node also it will  push  non leaf node value when one left is null and right is not null aor when right is null left not null
        if(root==NULL){
            return;
        }

        if(root->left==NULL && root->right==NULL){
            n=(n*10)+root->val;
            cout<<"pushed : "<<n<<endl;
            out.push_back(n);
            return;
        }

        n=(n*10)+root->val;
        // cout<<"going left of : "<<root->val<<endl;
        DFS(root->left,out,n);
        // cout<<" came back to : "<<root->val<<endl;
        // cout<<"going right of : "<<root->val<<endl;
        DFS(root->right,out,n);
        return;

    }

    int sumNumbers(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        vector<int> out;
        
        DFS(root,out,0);
        int i=0;
        int result=0;
        while(i<out.size()){
            result=result+out[i];
            i++;
        }
        return result;
    }
};

// www.leetcode.com/problems/sum-root-to-leaf-numbers/