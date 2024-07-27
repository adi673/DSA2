class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //remainder,frequency
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            int remainder=sum%k;
            if(remainder<0){  //this is case for negative numbers, like when sum wnet negative
                remainder=remainder+k;
            }

            if(mp.find(remainder)!=mp.end()){
                count=count+mp[remainder];  //here we are adding mp[remainder] not '+1' beacuse lets take example [4,5,0,-2,3]. at 0 it consider [0] also and [5,0] also else it will consider only 1
            }
            mp[remainder]++;
        }
        return count;
    }
   
};


//two sum hashmaps approach
//very imp algo