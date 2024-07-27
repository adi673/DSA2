class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int len=s.length();

        for(int i=0; i<len; i++){
            if(s[i]=='(' || s[i]=='['|| s[i]=='{'){
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    if((s[i]==')'&& st.top()=='(') || (s[i]==']'&& st.top()=='[') || (s[i]=='}'&& st.top()=='{')){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    //imp case for input are just right parenthisis 
                    if(s[i]==')' || s[i]==']'|| s[i]=='}'){
                        return false;
                    }
                }
                
                
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};