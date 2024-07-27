// tabular + space optimized
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        vector<int>dp(n+1,-1);

        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2; i<n; i++){ 
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev2,prev1);
        // return dp[n-1];   don't do this since from last and second last stair we can climb up to top. so tae min of them
    }
};