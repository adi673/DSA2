class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size, false);  // to keep track of visited rooms
        stack<int> toVisit;  // stack to perform DFS
        toVisit.push(0);  // start with room 0
        visited[0] = true;  // mark room 0 as visited

        while (!toVisit.empty()) {
            int room = toVisit.top();
            toVisit.pop();
            // Visit all the rooms that can be unlocked by keys in the current room
            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = true;
                    toVisit.push(key);
                }
            }
        }

        // Check if all rooms are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
};

//revise x2
//simple performing DFS

//u can't to do this using reverse adjacency list;