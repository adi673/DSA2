class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int len=s.length();
        int i=0;
        int balance=0;
        stack<char> st;
        while (i < len) {
            if (s[i] == '(') {
                if (!st.empty() ) {
                    result += "(";
                }
                st.push(s[i]);
            } else { // s[i] == ')'
                st.pop();
                if (!st.empty()) {
                    result += ")";
                }
                
            }
            i++;
        }

        return result;
    }
};