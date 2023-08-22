//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int i , int j , vector<vector<int>>& Matrix , vector<vector<int>> &dp){
        if(i < 0 || j >= Matrix[0].size()) return -1e8; // as we are taking MAX of all
        if(i == 0) return Matrix[0][j];

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = Matrix[i][j] + solve(i - 1 , j , Matrix , dp);
        int left = Matrix[i][j] + solve(i - 1 , j - 1 , Matrix , dp);
        int right = Matrix[i][j] + solve(i - 1 , j + 1 , Matrix , dp);

        return dp[i][j] = max(up , max(right , left));
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix){ // N*N matrix
        vector<vector<int>> dp(N , vector<int>(N , -1));

        int maxi = -1e8;
        for(int j = 0 ; j < N ; j++){
            maxi = max(maxi , solve(N - 1 , j , Matrix , dp));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends