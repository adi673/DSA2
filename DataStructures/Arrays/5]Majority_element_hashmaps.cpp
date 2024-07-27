class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int half=(nums.size())/2;
        for(int i=0; i<nums.size(); i++){
            if( map[nums[i]]>0){
                map[nums[i]]=map[nums[i]]+1;
            }else{
                map[nums[i]]=1;
            }
            
        }
        unordered_map<int,int> ::iterator itr ;
        for(itr=map.begin(); itr!=map.end(); itr++){
            if(itr->second >half){
                return itr->first;
            }
        }
        return -1;
    }
};


//hashmaps
//basically keeping freuency of every element 