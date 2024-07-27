//optimal approach


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts_count(n + 1, 0); // Number of people each person trusts
        vector<int> trusted_by_count(n + 1, 0); // Number of people who trust each person

        for (const auto& edge : trust) {
            int u = edge[0];
            int v = edge[1];
            trusts_count[u]++;
            trusted_by_count[v]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (trusts_count[i] == 0 && trusted_by_count[i] == n - 1) {
                return i;
            }
        }
        
        return -1; // If no judge found
    }
};
