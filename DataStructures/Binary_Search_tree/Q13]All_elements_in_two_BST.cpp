
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements1, elements2;
        
        // In-order traversal to get sorted elements from both trees
        inorderTraversal(root1, elements1);
        inorderTraversal(root2, elements2);
        
        // Merge the two sorted lists
        return mergeSortedArrays(elements1, elements2);
    }

private:
    void inorderTraversal(TreeNode* root, vector<int>& elements) {
        if (!root) return;
        stack<TreeNode*> stack;
        TreeNode* current = root;
        
        while (current || !stack.empty()) {
            while (current) {
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            stack.pop();
            elements.push_back(current->val);
            current = current->right;
        }
    }

    vector<int> mergeSortedArrays(const vector<int>& list1, const vector<int>& list2) {
        vector<int> mergedList;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                mergedList.push_back(list1[i]);
                ++i;
            } else {
                mergedList.push_back(list2[j]);
                ++j;
            }
        }
        // Add remaining elements
        while (i < list1.size()) {
            mergedList.push_back(list1[i]);
            ++i;
        }
        while (j < list2.size()) {
            mergedList.push_back(list2[j]);
            ++j;
        }
        return mergedList;
    }
};

