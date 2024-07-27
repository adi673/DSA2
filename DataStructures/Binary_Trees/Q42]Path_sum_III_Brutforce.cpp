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
    void findSum(TreeNode* root, int target_sum, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        target_sum -= root->val;
        result.push_back(root->val);

        if (target_sum == 0) {
            count++;
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;
        }

        findSum(root->left, target_sum, result);
        findSum(root->right, target_sum, result);

        // Backtrack
        result.pop_back();
    }

    void traverse(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }

        //taking current node as starting of path
        vector<int> result;
        findSum(root, targetSum, result);

        // Recursively traverse left and right subtrees  which is not taking ucrrent node as starting of path
        traverse(root->left, targetSum);
        traverse(root->right, targetSum);
    }



    int pathSum(TreeNode* root, int targetSum) {
        // if(targetSum==0){
        //     return 0;
        // }
        traverse(root, targetSum);
        return count;
    }
};


// O(n^2) solution
// Brutforce apporach by dfs.
// by taking the current node in starting of the path and moving till we will get target and  and by not taking that current node in starting of path and taking its consecutive node and making two diffrent paths and check for target sum. this is just approach 