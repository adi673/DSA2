class Solution {
public:
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        vector<int> sorted_difficulty, sorted_profit;
        for (const auto& job : jobs) {
            sorted_difficulty.push_back(job.first);
            sorted_profit.push_back(job.second);
        }

        for (int i = 1; i < sorted_profit.size(); ++i) {
            sorted_profit[i] = max(sorted_profit[i], sorted_profit[i - 1]);
        }

        int profit_total = 0;
        for (int i = 0; i < worker.size(); ++i) {
            // Find the upper bound index
            auto it = upper_bound(sorted_difficulty.begin(), sorted_difficulty.end(), worker[i]);
            if (it != sorted_difficulty.begin()) {
                int idx = it - sorted_difficulty.begin() - 1;
                profit_total += sorted_profit[idx];
            }
        }

        return profit_total;
    }
};