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

    TreeNode* makeTree(int start, int end, vector<int>& nums){
        if(start>end){
            return NULL;
        }

        int max=INT_MIN;
        int max_i=-1;
        int i=start;
        for(int i=start; i<=end; i++){
            if(nums[i]>max){
                max=nums[i];
                max_i=i;
            }
            
        }
        TreeNode* newNode=new TreeNode(max);
        newNode->left=makeTree(start,max_i-1,nums);
        newNode->right=makeTree(max_i+1,end,nums);
        return newNode;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int size=nums.size()-1;
        return makeTree(0,size,nums);
    }
};

// Complexity:
// Time Complexity: 
// 𝑂(𝑛log𝑛)
// O(nlogn) in the average case and 
// 𝑂(𝑛^2)
// O(n^2) in the worst case due to the repeated search for the maximum element.
// Space Complexity: 
// 𝑂(𝑛)
// O(n) for the recursion stack in the worst case.


//!!!!IMP!!!!
// we can solve the problem in 𝑂(𝑛)
// O(n) time using a monotonic stack. The idea is to build the tree iteratively by maintaining a stack where elements are in decreasing order. This allows us to efficiently find the position where the current element fits as a parent or a right child.