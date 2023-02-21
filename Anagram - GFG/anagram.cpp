//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        vector<int> a1(26,0);
          vector<int> b1(26,0);
          for(char it: a){
              a1[it-'a']++;
          }
          for(char it: b){
              b1[it-'a']++;
          }
               for(int i=0;i<26;i++){
                   if(a1[i]!=b1[i])
                   return false;
               }
               return true;
        
        // Your code here
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends