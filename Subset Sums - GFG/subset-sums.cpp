//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{
private:
    void solve(int idx , int n , int temp , vector<int> &arr , vector<int> &ans ){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        temp += arr[idx];
        solve(idx + 1 , n , temp , arr, ans);
        temp -= arr[idx];
        solve(idx + 1 , n , temp , arr , ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N){
        vector<int> ans;
        int temp = 0;
        solve(0 , N , temp , arr , ans);
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends