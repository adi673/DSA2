class Solution {
public:
    string removeDuplicates(string s) {
          stack<char> st;
        int i=s.length()-1; 
        
        while(i>=0){
            if(st.empty() || st.top()!=s[i]){
                st.push(s[i]);
                i--;
            }else{
                st.pop();
                i--;
            }
        }    
        string result;
        while (!st.empty()) {
            result.append(1, st.top());  // Append character to result string
            st.pop();
        }
        
        return result;
    }
};