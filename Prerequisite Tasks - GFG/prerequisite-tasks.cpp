//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    //now toposort
	    queue<int> q;
	     vector<int> indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]){
	          indegree[it]++;
	        }
	    }
	    vector<int> ans;
	   	    for(int i=0;i<N;i++){
	     if(indegree[i]==0)
	     q.push(i);
	    }
	 
	    while(!q.empty()){
	        int node =q.front();
	        q.pop();
	     ans.push_back(node);
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	    
	    if(N==ans.size())
	    return true;
	      return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends