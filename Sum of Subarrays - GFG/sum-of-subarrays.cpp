//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        //observation:
        //any element arr[i] will be present in i+1 subarrays
        // 
       long long mod =1e9+7; 
        long long sum=0;
        for(int i=0;i<n;i++){
            sum= (sum% mod) + ((a[i]*(i+1)*(n-i))% mod);
        }
        return sum % mod;
        
        
        
        
        // Your code goes here
        /*long long int sum=0;
        
        long long int prefixsum[n] ={0};
    prefixsum[0] =a[0];
    for(int i=1;i<n;i++){
        prefixsum[i] =prefixsum[i-1]+a[i];
    }
    // for(int i=0;i<n;i++){
    //     cout<<prefixsum[i]<<" ";
    // }
    if(n%2!=0){
        long long k =(n/2)+1;
        for(int i=0;i<n;i++){
            sum+=prefixsum[i]*k;
        }
        return sum % 100000009;
    }
    else{
        float  k1 =(n/2)+0.5;
        float sumi=0.0;
        for(int i=0;i<n;i++){
            sumi+=prefixsum[i]*k1;
        }
        long long int ans =sumi;
        return ans % 100000009;
    }
    return 0;
    */
    }
};

//{ Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}

// } Driver Code Ends