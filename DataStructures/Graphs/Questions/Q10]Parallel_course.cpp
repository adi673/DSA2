class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
       vector<vector<int>> adj(n + 1);  // Adjacency list
        vector<int> inDegree(n + 1, 0);  // In-degrees
        vector<int> completionTime(n + 1, 0);  // Completion times

        // Build the graph and in-degrees
        for (const auto& relation : relations) {
            int prev = relation[0];
            int next = relation[1];
            adj[prev].push_back(next);
            inDegree[next]++;
        }

        // Queue for topological sort
        queue<int> q;
        // Initialize the queue with nodes having zero in-degree
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                completionTime[i] = time[i - 1];  // Course i is (i-1)th index in time
            }
        }

        // Topological sort with DP to calculate completion times
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            for (int nextCourse : adj[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
                // Update the completion time for the next course
                completionTime[nextCourse] = max(completionTime[nextCourse], completionTime[course] + time[nextCourse - 1]);
            }
        }

        // The result is the maximum value in the completionTime array
        return *max_element(completionTime.begin(), completionTime.end());

    }
};
//revise 2x 
//topological sort
//https://leetcode.com/problems/parallel-courses-iii/
// https://youtu.be/743cYtf3DJI
