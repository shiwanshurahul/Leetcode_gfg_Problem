//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
public:	
int solve(int *arr, int n,int i,  vector<int> &dp){
    if(i>=n)
    return 0;
    
    if(dp[i]!=-1)
    return dp[i];
    int a =arr[i] +solve(arr,n,i+2,dp);
    int b = solve(arr,n,i+1,dp);
    if(a>b)
    return dp[i] = a;
    return dp[i] =b;
}
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(arr,n,0,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends