class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }

        unordered_map<int,int> mp; //storing sum, freq
        int count=0;
        int sum=0;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            if(mp.find(sum-k)!=mp.end()){
                count=count+mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }

    
};

//TwO SUM hash map apporach.
//storing 1 for odd number and 0 for even number
// and after that same two sum approach of haspmaps