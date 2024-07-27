class Solution {
public:
    bool isPalindrome(int x) {
        int num=x;
        stack<int>st;
        if(x<0){
            return false;
        }
        while(num!=0){
            int rem=num%10;
            st.push(rem);
            num=num/10;
        }
        num=x;
        

        while(!st.empty()){
            int rem=num%10;
            num=num/10;
            if(rem!=st.top()){
                break;
            }
            st.pop();

        }

        if(st.empty()){
            cout<<"came inside this"<<endl;
            return true;
        }
        return false;
    }
};