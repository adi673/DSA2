class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=1; i<size; i++){
            if(nums[i]<=nums[i-1]){
                moves=moves+(nums[i-1]-nums[i]+1);
                nums[i]=nums[i-1]+1;
            }
        }
        return moves;
    }
};