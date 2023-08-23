//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++


class Solution{   
private:
    bool solve(int n , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(target == 0) return true;
        if(n == 0) return target == nums[0];

        if(dp[n][target] != -1 )
            return dp[n][target];

        bool notTake = solve(n - 1 , target , nums , dp);
        bool take = false;
        if(nums[n] <= target) take = solve(n - 1 , target - nums[n] , nums , dp);

        return dp[n][target] = take | notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int> (sum + 1 , -1));
        return solve(n - 1 , sum , arr , dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends