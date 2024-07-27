//brutforce 


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            int sum=nums[i];
            cout<<"sum start is : "<<sum<<endl;
            
            for(int j=i+1; j<nums.size(); j++){
                sum=sum+nums[j];
                cout<<"adding  : "<<nums[j]<<endl;
                cout<<"sum : "<<sum<<endl;
                if(sum%k==0){
                    return true;
                }
            }
            
        }
        return false;
    }
};