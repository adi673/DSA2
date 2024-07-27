class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;//sum,freq
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            int remain=sum-k;
            if(mp.find(remain)!=mp.end()){
                count=count+mp[remain];
            }
            mp[sum]++;
        }
        return count;
    }
};


//two sum hashmaps approach
//very imp algo
// revise algo x2