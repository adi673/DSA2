//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

public:
    int minCoins(vector<int> &coins, int M, int V) { 
        vector<int>ans;
        int n=V;
        int val;
        for (int i = n - 1; i >= 0; i--) {
            while (val >= coins[i]) {
                val -= coins[i];
                ans.push_back(coins[i]);
            }
        }
        return ans.size();
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
//revise once
//Date 14/07/2024
//gfg