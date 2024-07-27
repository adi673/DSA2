class Solution {
public:
    int fib(int n) {
        int prev2=0;
        int prev1=1;
        int curr=0;
        if(n<=1){
            return  n;
        }
        for(int i=2; i<=n; i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};