class Solution {
public:
    string removeKdigits(string num, int k) {
       string result = "";

        for (char digit : num) {
        
            while (k > 0 && !result.empty() && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

    
        result.resize(result.size() - k);

   
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }    
    
};