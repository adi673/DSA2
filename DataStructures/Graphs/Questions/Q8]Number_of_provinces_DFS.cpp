class Solution {
public:
    // Perform DFS to mark all connected cities
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(isConnected, visited, neighbor);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        // Traverse each city
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                // Found a new province, start DFS from city i
                provinces++;
                dfs(isConnected, visited, i);
            }
        }

        return provinces;
    }
};