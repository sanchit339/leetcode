//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    int knapSack(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n , vector<int>(W + 1 , 0));
        
        // base case
        for(int weight = wt[0] ; weight <= W ; weight++){ // at this will theaf
            dp[0][weight] = val[0]; // for all weight we can steal and get the val
        }

        for(int idx = 1 ; idx < n ; idx++){
            for(int weight = 0 ; weight <= W ; weight++){
                int notTake = dp[idx - 1][weight];
                int take = INT_MIN;
                if(wt[idx] <= weight) take = val[idx] + dp[idx - 1][weight - wt[idx]];

                dp[idx][weight] = max(notTake , take);
            }
        }
        return dp[n - 1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends