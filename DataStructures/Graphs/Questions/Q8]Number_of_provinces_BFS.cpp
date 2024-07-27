class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        // Queue for BFS
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Start BFS from city i
                q.push(i);
                provinces++;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    visited[curr] = true;

                    for (int j = 0; j < n; ++j) {
                        if (isConnected[curr][j] == 1 && !visited[j]) {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};