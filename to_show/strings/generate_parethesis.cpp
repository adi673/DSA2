class Solution {
public:
    void generate(int left, int right, std::string current, std::vector<std::string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        
        if (left > 0) {
            generate(left - 1, right, current + "(", result);
        }
        
        if (right > left) {
            generate(left, right - 1, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate(n, n, "", result);
        return result;
    }
};