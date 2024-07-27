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
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*> leaf_node;

        makeGraph(root,NULL,leaf_node,adj);
        int count=0;
        
        for(auto& leaf: leaf_node ){
            queue<TreeNode*> q;
            q.push(leaf);
            unordered_set<TreeNode*> visited;
            visited.insert(leaf);
           for(int level=0; level<=distance; level++){
                int size=q.size();
                while(size--){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr!=leaf &&  leaf_node.count(curr)){
                        count++;
                    }
                    for(auto nebr: adj[curr] ){
                        if(!visited.count(nebr)){
                            q.push(nebr);
                            visited.insert(nebr);
                        }
                    }
                }
           }
           
        }
        return count/2;
    }

private:
    void makeGraph(TreeNode* root,TreeNode* prev, unordered_set<TreeNode*>& leaf_node,map<TreeNode*,vector<TreeNode*>>& adj){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            leaf_node.insert(root);
        }
        if(prev){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        makeGraph(root->left,root,leaf_node,adj);
        makeGraph(root->right,root,leaf_node,adj);
        return;
    }
};


//revise approac 2x
//convertng tree in undirected graph
// https://youtu.be/vrbJ7aDuK-A