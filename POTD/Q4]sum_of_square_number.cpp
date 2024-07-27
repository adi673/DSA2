class Solution {
public:
    long long square(long long x) {
      return x * x;
    }   
    bool judgeSquareSum(int c) {
        long long end=sqrt(c);
        cout<<end<<endl;
        long long start=0LL;
        while(start<=end){
            if((square(start)+ square(end))<c){
                start++;
            }else if((square(start)+ square(end))>c){
                end--;
            }else{
                return true;
            }
        }
        return false;
    }
};