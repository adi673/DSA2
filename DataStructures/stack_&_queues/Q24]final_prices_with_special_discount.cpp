class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int> result(prices);
        for(int i=0; i<prices.size(); i++){
           while(!st.empty() && prices[st.top()]>=prices[i]){
                int re= prices[st.top()]-prices[i];
                result[st.top()]=re;
                st.pop();
           }
           st.push(i);
        }
        // while(!st.empty()){
        //     result[st.top()]=prices[st.top()];
        //     st.pop();
        // }

        return result;
    }
};


//approach 
// https://www.youtube.com/watch?v=3_BAIugNaL/w