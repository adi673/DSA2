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

    TreeNode* build(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd,unordered_map<int,int>& mp){
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }

        int val=postorder[postEnd];
        TreeNode* newNode= new TreeNode(val);
        int index=mp[val];
        int rightTreeSize=inEnd-index;

        
        newNode->left=build(postorder, postStart,postEnd-rightTreeSize-1,inorder,inStart, index-1,mp);
        newNode->right=build(postorder,postStart-rightTreeSize,postEnd-1, inorder, index+1, inEnd,mp);

        return newNode;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }

        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};

//revise it again. x1

//rightTreeSize variable is imp in logic
//started from postEnd as starting node will be in end of postorder

// www.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/