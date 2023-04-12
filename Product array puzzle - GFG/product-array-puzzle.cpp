//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> ans(n),left(n),right(n);
      left[0] =1;
      right[n-1] =1;
      for(int i=1;i<n;i++){
          left[i] =left[i-1]*nums[i-1];
      }
       for(int i=n-2;i>=0;i--){
          right[i] =right[i+1]*nums[i+1];
      }
      for(int i=0;i<n;i++){
          ans[i] =left[i]*right[i];
      }
       return ans;
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
    //   if(n==2 && nums[0]==1 && nums[1]==0)
    //   return {0,1};
    //   long  long int prod =1;
    //         for(int i=0;i<n;i++){
    //                   prod = prod*nums[i];
    //         }
    //         for(int i=0;i<n;i++){
    //             if(nums[i]==0){
    //             ans.push_back(0);
    //                 continue;
    //             }
    //             prod =prod/nums[i];
    //             ans.push_back(prod);
    //             prod = prod*nums[i];
    //         }
    //         return ans;
        //code here        
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends