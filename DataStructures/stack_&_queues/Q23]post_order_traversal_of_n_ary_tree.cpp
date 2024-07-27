/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void givecall(Node* root, stack<int>& st){
        if(root==NULL){
            return;
        }
        st.push(root->val);
        for(int i=root->children.size()-1; i>=0; i--){
            givecall(root->children[i],st);
        }
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int>result;
        stack<int>st;
        givecall(root,st);
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;

    }
};