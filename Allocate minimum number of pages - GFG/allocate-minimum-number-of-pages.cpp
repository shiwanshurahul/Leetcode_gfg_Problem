//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool ispossible(int A[],int n,int mid,int M){
         int pagesum=0;
         int studentcnt =1;
         for(int i=0;i<n;i++){
             if(pagesum+A[i]<=mid){
             pagesum+=A[i];
             }
             
             else{
             studentcnt++;
             if(studentcnt >M || A[i]>mid)
                 return false;
                 else
                 pagesum=A[i];
            } 
         }
         return true;
        
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N)
        return -1;
        int n =N;
        int sum =0;
        for(int i=0;i<N;i++)
        sum+=A[i];
        
        int s=0,e =sum;
        int ans=0;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(ispossible(A,n,mid,M)){
            ans = mid;
            e= mid-1;}
            else{
                s =mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends