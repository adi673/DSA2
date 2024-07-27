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
    TreeNode* deleteNode(TreeNode* root, int key) {
         if (root == nullptr) return root;

        if (key < root->val) {
            // If the key to be deleted is smaller than the root's key,
            // then it lies in the left subtree.
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // If the key to be deleted is greater than the root's key,
            // then it lies in the right subtree.
            root->right = deleteNode(root->right, key);
        } else {
            // If the key is the same as the root's key, then this is the node
            // to be deleted.
            
            // Node with only one child or no child.
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the in-order successor
            // (smallest in the right subtree).
            TreeNode* temp = minValueNode(root->right);

            // Copy the in-order successor's content to this node.
            root->val = temp->val;

            // Delete the in-order successor.
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        // Loop down to find the leftmost leaf.
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }
};