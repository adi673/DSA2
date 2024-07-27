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
    void inOrder(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    TreeNode* createBST(vector<int>& inorder, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = (high + low) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = createBST(inorder, low, mid - 1);
        root->right = createBST(inorder, mid + 1, high);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        // First create inorder sequence of given BST
        vector<int> inorder;
        inOrder(root, inorder);
        
        // For debugging: print the inorder sequence
        for (int i = 0; i < inorder.size(); ++i) {
            cout << inorder[i] << endl;
        }
        
        // Construct a balanced BST from the inorder sequence
        return createBST(inorder, 0, inorder.size() - 1);
    }
};


// first convert to inOrder sequence and then construct it 