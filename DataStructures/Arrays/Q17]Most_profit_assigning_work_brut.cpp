class Solution {
public:
    int find_profit(vector<int>& difficulty, vector<int>& profit,  int worker_strength) {
        int max_profit = 0;
        for (int i = 0; i < difficulty.size() && worker_strength >= difficulty[i]; i++) {
            max_profit = max(max_profit, profit[i]);
        }
        return max_profit;
    }
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

        int profit_total=0;
        for (int i = 0; i < worker.size(); i++) {
           profit_total+=find_profit(sorted_difficulty, sorted_profit, worker[i]);
        }
        return profit_total;
    }
};