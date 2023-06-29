//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ismatches(char ch,char top){
        if((ch=='}' && top=='{') || (ch==')' && top=='(') || (ch==']' && top=='['))
        return 1;
        else
        return 0;
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        for(int i=0;i<x.length();i++){
            char ch =x[i];
            if(ch=='{' || ch=='(' || ch=='['){
                st.push(ch);
            }
            else if(ch=='}' || ch==')' || ch==']'){
                if(!st.empty()){
                    char chh =st.top();st.pop();
                if(!ismatches(ch,chh))
                return false;
            }
            else if(st.empty()){ //st is empty with } || ] || )
                return false;
            }
        }
        }
        if(st.empty())
        return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends