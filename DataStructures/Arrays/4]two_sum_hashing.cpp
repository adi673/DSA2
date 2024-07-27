class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> m;
       int n=nums.size();
       vector<int> v;
       for(int i=0; i<n;i++){
          int num=nums[i];
          int need=target-num;
          if (m.find(need) != m.end()) {
            return {m[need], i};
        }
        m[num] = i;
        }
        return {-1,-1};

        
    }
};