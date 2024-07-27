class Solution {
public:
    bool isValidSerialization(string preorder) {
         istringstream iss(preorder);
        string token;
        vector<string> nodes;

        while (getline(iss, token, ',')) {
            nodes.push_back(token);
        }

        int slots = 1; // Number of available slots for nodes

        for (const string& node : nodes) {
            if (slots <= 0) return false; // More nodes than available slots

            if (node == "#") {
                slots--; // Consume a slot for null node
            } else {
                slots++; // Consume a slot for non-null node, but add 2 slots for its children
            }
        }

        return slots == 0; // All slots should be consumed at the end
    }
    
};

//not even understood. do  the hwole question again
//leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/78551/7-lines-Easy-Java-Solution