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
    TreeNode* createBST(int min, int max, vector<int>& nums) {
        if (min > max) {
            return nullptr;
        }

        int mid = min + (max - min) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = createBST(min, mid - 1, nums);
        root->right = createBST(mid + 1, max, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(0, nums.size() - 1, nums);
    }
};

//revise x2 half is cgpt