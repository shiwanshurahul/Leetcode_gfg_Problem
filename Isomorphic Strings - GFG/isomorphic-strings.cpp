//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code her
        if(str1.length() !=str2.length())
        return 0;
       int ss[256]= {0};
       int ts[256]= {0};
          for(int i=0;i<str1.size();i++){
            if(!ss[str1[i]] && !ts[str2[i]]){
                ss[str1[i]]= str2[i];
                ts[str2[i]] =str1[i];
            }
            else if(ss[str1[i]] != str2[i])
            return false;
          }
          return 1;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends