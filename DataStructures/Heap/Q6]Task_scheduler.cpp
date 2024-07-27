class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<long long> maxheap;
        vector<int> chart(26,0);

        for(auto ch : tasks){
            chart[ch-'A']++;
        }

        for(int i=0; i<26; i++){
            if(chart[i]>0){
                maxheap.push(chart[i]);
            }
        }
        int num=0;
        while(!maxheap.empty() ){
            vector<int>temp;
            for(int i=1; i<=n+1; i++){
                if(!maxheap.empty()){
                    int freq=maxheap.top();
                    maxheap.pop();
                    freq--;
                    temp.push_back(freq);
                    
                }
            }

            for(auto it : temp){
                if(it>0){
                    maxheap.push(it);
                }
            }

            if(maxheap.empty()){
                num=num+temp.size();
            }else{
                num=num+n+1;
            }

        }
        return num;
    }
};

//revise 4x logic
// https://youtu.be/rYh-Kkbzsnw