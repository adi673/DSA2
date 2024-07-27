class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> freq;//element,freq

        int i=0;
        for(auto &num : arr1){
            freq[num]++;
        }

       
        vector<int>result;
        for(auto &num : arr2){
            while (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        vector<int> rem;
        // Add the remaining elements that are not in arr2
        for (auto &num2 : freq) {
            while (num2.second > 0) {
                rem.push_back(num2.first);
                num2.second--;
            }
        }


        sort(rem.begin(),rem.end());
        result.insert(result.end(), rem.begin(), rem.end());
        return  result;
    }
};