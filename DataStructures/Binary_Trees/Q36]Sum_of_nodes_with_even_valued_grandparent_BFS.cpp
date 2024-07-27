class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;
        queue<tuple<TreeNode*, TreeNode*, TreeNode*>> q;
        q.push({root, nullptr, nullptr});

        while (!q.empty()) {
            auto [node, parent, grandparent] = q.front();
            q.pop();

            if (grandparent && grandparent->val % 2 == 0) {
                sum += node->val;
            }

            if (node->left) {
                q.push({node->left, node, parent});
            }

            if (node->right) {
                q.push({node->right, node, parent});
            }
        }

        return sum;
    }
};

//don't even tried this code. solve this BFS approach again. and after that revise it 2x times.