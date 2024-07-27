class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if (customers.empty()) {
            return 0;
        }

        if (customers.size() < minutes) {
            return 0;
        }   
        
        int max_sum = 0;
        for (int i = 0; i <minutes; ++i) {
            if(grumpy[i]==1){
                max_sum += customers[i];
            }
            
        }
        int window_sum = max_sum;
    
        // Slide the window from start to end of the array
        for (int i = minutes; i < customers.size(); ++i) {
            if(grumpy[i]==1){
                window_sum += customers[i];
            }
            if(grumpy[i-minutes]==1){
                window_sum=window_sum-customers[i -minutes];
            }
            max_sum =max(max_sum, window_sum);
        }

        for(int i=0; i<customers.size(); i++){
            if(grumpy[i]==0){
                max_sum=max_sum+customers[i];
            }
        }
        return max_sum;
    }
};