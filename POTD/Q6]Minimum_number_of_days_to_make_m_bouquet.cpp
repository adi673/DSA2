class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k, int Day){
        long long  val=0LL;
        int count=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=Day){
                count++;
            }else{
                val=val+(count/k);
                count=0;
            }
        }

        val=val+(count/k);
        return val>=m;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long size = static_cast<long long>(m) * k;
        if(bloomDay.size()<size){
            return -1;
        }
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        cout<<low<<" and "<<high<<endl;

        while(low<=high){
            int mid=(low+high)/2;

            if(possible(bloomDay, m, k, mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};

//revise 2x