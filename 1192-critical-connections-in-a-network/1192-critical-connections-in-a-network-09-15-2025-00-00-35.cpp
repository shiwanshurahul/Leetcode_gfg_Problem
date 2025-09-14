class Solution {
public:
//const 2 = edges hai
vector<vector<int>> ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //bridges ins a graph -> tarjan's algorithm
        unordered_map<int, vector<int>> adj;
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int timer = 0;
        vector<int> disc(n,-1);
        vector<int> vis(n,0);
        vector<int> low(n,-1);
      
        dfs(0,adj,vis,timer,disc,low,-1);

        return ans;
    }
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>&vis, int timer, vector<int>& disc, vector<int>&low, int parent){
        vis[node] = 1;
        disc[node] = low[node] = timer++;

        for(auto it: adj[node]){
            if(it==parent)
                continue;
            if(!vis[it]){
                dfs(it,adj,vis,timer,disc,low,node);
                low[node] = min(low[node], low[it]);
                //check edge is bridge or not
                if(low[it] > disc[node])
                    ans.push_back({it,node});
            }    
            else {  //visited hai it = back edge hai 
                low[node] = min(low[node], low[it]);
            }    
        }
        return;
    }
};