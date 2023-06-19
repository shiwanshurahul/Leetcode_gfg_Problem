//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool dfs(int node,vector<int>&vis,vector<int> adjlist[]){
      vis[node] =1;
      for(auto child:adjlist[node]){
          if(!vis[child])
          dfs(child,vis,adjlist);
      }
      return true;
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V,0);
        vector<int> adjlist[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adjlist);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends