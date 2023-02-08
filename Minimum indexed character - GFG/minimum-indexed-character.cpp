//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        int l =1e9;
        int i=0;
        while(i<patt.length()){
             int k =str.find(patt[i]);
              if(k!=-1){
           l = min(l,k);
               i++;
           }
           else{
           i++;
        }
        k =0;
        }
        if(l==1e9)
        return -1;
        return l;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        string str;
        string patt;
        cin>>str;
        cin>>patt;
        Solution obj;
        cout<<obj.minIndexChar(str, patt)<<endl;
    }
	return 0;
}

// } Driver Code Ends