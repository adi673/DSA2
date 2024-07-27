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
    void inorderTraversal(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, prev, first, second);

    // If the previous node's value is greater than the current node's value,
    // it indicates a misplaced node. Update the 'first' and 'second' nodes accordingly.
    if (prev != NULL && prev->val > root->val) { //jaise hi ham 2 pe jayenge hame pata lagega 3 wrong node hai and wrt 2 wrong node nhi hai but agar ham swap karenge to glat ho jayega kuki 1 ke right mai sab chote nodes hone chahiye .ye check karne ke liye  ham vo 2 ka prev karke usake successor ko check karenge and galat ho too vo next node second ko assign karenge and finally swap akrenge. fist and second imp stratagy haitest case [1,3,n,n,2]
        if (first == NULL)
            first = prev;
        second = root;
    }
    prev = root;

    inorderTraversal(root->right, prev, first, second);
}

void recoverTree(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    // Find the misplaced nodes
    inorderTraversal(root, prev, first, second);

    // Swap the values of the misplaced nodes
    swap(first->val, second->val);
}


};