class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while (!stk.empty() && stk.top()->val < num) {
                curr->left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top()->right = curr;
            }
            stk.push(curr);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};

//not even  studied this apporach. approach given by chatgppt
// learn it and the nrevise it