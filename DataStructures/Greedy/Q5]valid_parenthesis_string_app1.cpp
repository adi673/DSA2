class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int> star;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                open.push(i);
            }else if(s[i]==')'){
                if(!open.empty()){
                    open.pop();
                }else if(!star.empty() && star.top()<i){
                    star.pop();
                }else{
                    return false;
                }
            }else{
                star.push(i);
            }
        }
        
        while(!open.empty() && !star.empty()){
            if(open.top()>star.top()){
                return false;
            }
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};
//revise 2x
//Date 14/07/2024
//https://youtu.be/Pno2hATcwHA?t=2798

//imp to keep track of index of opening and * for closing bracket we want opening  bracket or * having index lesser than index of closng bracket