//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
   int recursionCount(vector<int>& coins, int left_V, int index) {
        if (left_V == 0) {
            return 0;
        }
        if (left_V < 0 || index >= coins.size()) {
            return INT_MAX;
        }
        
        // Do not take the current coin
        int not_take = recursionCount(coins, left_V, index + 1);
        
        // Take the current coin
        int take = recursionCount(coins, left_V - coins[index], index);
        if (take != INT_MAX) {
            take += 1;
        }
        
        return min(take, not_take);
    }

public:
    int minCoins(vector<int> &coins, int M, int V) { 
        int result = recursionCount(coins, V, 0);
        return (result == INT_MAX) ? -1 : result;
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends