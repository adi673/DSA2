class Solution {
public:
  

    int findExcess(TreeNode* root,int& moves){
        if(root==NULL){
            return 0;
        }

        int leftExcess=findExcess(root->left,moves);
        int rightExcess=findExcess(root->right,moves);

        int excess=root->val+leftExcess+rightExcess-1;
        moves=moves+abs(leftExcess)+abs(rightExcess);
        return excess;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        findExcess(root,moves);
        return moves;
    }
};


//revise x3 

// Tree Structure:

// We have a binary tree where each node has a certain number of coins (node.val).
// The total number of coins is equal to the total number of nodes, ensuring there are enough coins to distribute exactly one coin per node.
// Goal:

// Make every node have exactly one coin.
// Move Definition:

// A move involves transferring one coin between two adjacent nodes (either parent to child or child to parent).



//Approach:

// To achieve the goal, we use a postorder traversal (left, right, root) of the tree. The core idea is to balance the coins starting from the leaves towards the root, ensuring that we account for the excess or deficit of coins at each node.

// Detailed Steps
// Excess Calculation:

// For each node, calculate the excess coins after making sure the node has one coin itself. The excess coins can be positive (more than one coin) or negative (less than one coin).
// The formula for excess coins at a node is:
// excess=node.val+left.excess+right.excess−1
// excess=node.val+left.excess+right.excess−1
// Here, left.excess and right.excess are the excess coins from the left and right subtrees respectively.
// Move Count:

// The number of moves required to balance a subtree is the sum of the absolute values of excess coins from the left and right children.
// Moves are accumulated as we propagate the excess coins up towards the root.
// Recursion:

// Use recursion to perform a postorder traversal, ensuring we first balance the left and right subtrees before the current node.