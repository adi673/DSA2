class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        std::string previous = countAndSay(n - 1);
        std::string result = "";

        int count = 1;
        for (size_t i = 1; i < previous.size(); ++i) {
            if (previous[i] == previous[i - 1]) {
                count++;
            } else {
                result += std::to_string(count) + previous[i - 1];
                count = 1;
            }
        }
        result += std::to_string(count) + previous.back();

        return result;
    }
};