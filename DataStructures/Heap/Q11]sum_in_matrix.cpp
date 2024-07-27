class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        

        int rows = nums.size();
        int cols = nums[0].size();
        int score = 0;
        vector<priority_queue<int>> maxheap(rows);
        for(int i=0; i<rows; i++){
            for(auto num : nums[i]){
                maxheap[i].push(num);
            }
        }

        while(!maxheap[0].empty()){
            int maxInStep=INT_MIN;
            for(int i=0; i<rows; i++){
                if (!maxheap[i].empty()) {
                    int maxNum = maxheap[i].top();
                    maxheap[i].pop();
                    maxInStep = max(maxInStep, maxNum);
                }
            }
            score=score+maxInStep;
        }
        return score;
    }
};

//revvise 2x
