class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int count=0;
        priority_queue<int> maxHeap;
        for (const auto& row : matrix) {
            
            for (int element : row) {
                count++;
                if(count<=k){
                    cout<<"pushing : "<<element<<endl;
                    maxHeap.push(element);
                }else{
                    if(element<maxHeap.top()){
                        cout<<"poping : "<<maxHeap.top()<<endl;
                        maxHeap.pop();
                        cout<<"pushing : "<<element<<endl;
                        maxHeap.push(element);
                    }
                }
            }
        }
        cout<<maxHeap.top()<<endl;
    return maxHeap.top();
       
    }
};