//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        reverse(pre_exp.begin(), pre_exp.end());
        int size=pre_exp.length();
        stack<string>st;
        string infix;
        for(int i=0; i<size; i++){
            char c=pre_exp[i];
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                 st.push(string(1, c));
            }else{
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                
                string expr = '(' + op1 + c + op2 + ')';
                st.push(expr);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends