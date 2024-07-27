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
    int count=0;
    void find(TreeNode* root, int targetSum,long long sum, unordered_map<long long,int>& mp){

        if(root==NULL){
            return ;
        }
        
        sum=sum+root->val;
        long long  remain=sum-targetSum;
        if(mp.find(remain)!=mp.end()){
            count=count+mp[remain];
        }
        mp[sum]++;
       
        find(root->left,targetSum, sum,mp);
        find(root->right,targetSum,sum,mp);
        
        mp[sum]--;
    }


    int pathSum(TreeNode* root, int targetSum) {
       unordered_map<long long,int> mp;
       mp[0]=1;

       find(root,targetSum, 0LL,mp);
        return count;
    }
};


//O(n) apporach using prefix sum and map

// https://youtu.be/yyZA4v0x16w
//https://youtu.be/uZzvivFkgtM