class Solution {
public:
    int maxDepth(string s) {
         int max=0;
    int i=0;
    stack <char> st;
    while(i<s.length()){
        cout<<"max val: "<<max<<endl;
        if(s[i]==')'){
            st.push(s[i]);
            cout<<"pushing : "<< s[i] <<endl;
            max++;
            i++;
        }else if(s[i]=='('&& st.empty()){
            i++;
        }else if(s[i]=='('&& st.top()==')'){
            max--;
            cout<<"popping : "<< st.top() <<endl;
            st.pop();
            i++;
        }else{
            i++;
        }
    }
    return max;

    }
};