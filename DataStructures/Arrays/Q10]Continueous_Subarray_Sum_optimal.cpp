class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> remaindermap; //remainder,index
        remaindermap[0]=-1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            int remainder=sum%k;

            if(remaindermap.find(remainder)!=remaindermap.end()) {
                if(i-remaindermap[remainder]>1){
                    return true;
                }
            }else{
                remaindermap[remainder]=i;
            }   
            
        }
        return false;
    }
};

//concept we are using here is that in O(n) we are adding every element and caculating their remainder simoultaneously. and storing it [remainder,index] in map.after calculating remainder if we had any same remander before for the sum if we get same remainder before means from that index till currect index array contributed in the multiple of k. in short n*k is added means after that index to curent index containing subarray is divisible by k. so return true;
//we will store in map as [remainder,index] so that we can get the index on the bases of  remainder, because we can only check key in maps not value and we have to check remainder so we will kepp it on left side. and we can check if the difference of the index is greater than 1 or not. if it is greater than 1 then we can say that there is a subarray which is divisible by k.

//mention this logic in book. revise x1