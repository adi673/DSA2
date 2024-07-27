//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        int n = arr.size();
    
        // Min-heap to store elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
    
        // Insert all elements into the min-heap
        for (int i = 0; i < n; ++i) {
            minHeap.push(arr[i]);
        }
    
        // Map to store the rank of each element
        unordered_map<int, int> rankMap;
    
        // Assign ranks while extracting elements from the min-heap
        int rank = 1;
        while (!minHeap.empty()) {
            int value = minHeap.top();
            minHeap.pop();
        
            // Only assign rank if the element is not already assigned
            if (rankMap.find(value) == rankMap.end()) {
                rankMap[value] = rank++;
            }
        }
    
        // Replace elements in the original array with their ranks
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = rankMap[arr[i]];
        }
    
        return result;
    

    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends


//revise 2x
// www.geeksforgeeks.org/replace-element-array-rank-array/