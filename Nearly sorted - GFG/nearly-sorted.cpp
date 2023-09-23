//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> ans;
        priority_queue<int , vector<int> , greater<int>> mq;
        for(int i = 0 ; i < num ; i++){
            mq.push(arr[i]);
            if(mq.size() == K + 1){
                ans.push_back(mq.top());
                mq.pop();
            }
        }
        while(!mq.empty()){
            ans.push_back(mq.top());
            mq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends