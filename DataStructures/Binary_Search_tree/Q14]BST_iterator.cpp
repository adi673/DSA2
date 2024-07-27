//question is not touugh. but this type of question  like they give class initially and some function and we have to implement it are need to practise and hard to understand.
class BSTIterator {
        queue<int> q;
private:

    void iterate(TreeNode* root){
        if(!root){
            return;
        }
        iterate(root->left);
        q.push(root->val);
        iterate(root->right);
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        if(!root){
            return;
        }
        iterate(root);
    }
    
    int next() {
        int val=q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        if(q.empty()){
            return false;
        }
        return true;
    }
};
//https://leetcode.com/problems/binary-search-tree-iterator/