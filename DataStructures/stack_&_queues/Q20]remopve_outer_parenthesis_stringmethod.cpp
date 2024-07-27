#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0; // To track the balance of parentheses
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {
                    result += c; // Add '(' if not the outermost '('
                }
                balance++; // Increase balance
            } else { // c == ')'
                balance--; // Decrease balance
                if (balance > 0) {
                    result += c; // Add ')' if not the outermost ')'
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "(()())(())";
    cout << "Output: " << solution.removeOuterParentheses(s) << endl;
    return 0;
}
