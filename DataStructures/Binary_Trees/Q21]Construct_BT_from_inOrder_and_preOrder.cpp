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

    TreeNode* build(vector<int>& preorder , int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp){
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        int val = preorder[preStart];
        TreeNode* newNode = new TreeNode(val);
        int index = mp[val];
        int leftTreeSize = index - inStart;

        newNode->left = build(preorder,preStart + 1, preStart + leftTreeSize, inorder, inStart, index - 1,  mp);
        newNode->right = build(preorder, preStart + leftTreeSize + 1, preEnd, inorder, index + 1, inEnd, mp);
        
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,  mp);
        
    }
};

// revise x1
// www.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

//revise it again x very imp logic

//leftTreesize variable is imp in logic