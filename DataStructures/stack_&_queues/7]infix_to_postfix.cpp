//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int pre(char s){
        if(s=='^'){
            return 3;
        }else if(s=='*' || s=='/'){
            return 2;
        }else if(s=='+' || s=='-'){
            return 1;
        }
        return -1;
    }
    
    string infixToPostfix(string s) {
        stack<char> st;
        int len=s.length();
        string postfix;
        for(int i=0; i<len; i++){
            char c=s[i];
            
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
                postfix=postfix+c;
            }else if(c=='('){
                st.push(c);
            }else if(c==')'){
                while(!st.empty() &&st.top()!='('){
                    postfix=postfix+st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
            }else{
                 while (!st.empty() && pre(c) <= pre(st.top())) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }    
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
            
            
        
        
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends