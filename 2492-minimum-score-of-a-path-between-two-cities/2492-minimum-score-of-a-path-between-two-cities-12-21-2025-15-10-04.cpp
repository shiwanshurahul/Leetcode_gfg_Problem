class Solution {
public:
void dfs(int node, vector<int>&vis, int &mini, unordered_map<int, vector<pair<int,int>>>& adj){
    vis[node] = 1;
    // mini = min(mini, node);  //node ki val ni chahiye wt chaiye

    for(auto it: adj[node]){  //pair hai = it.first, it.second;
            int wt = it.second;
            mini = min(mini, wt); 
            if(!vis[it.first]){  //it.first is v and it.second is wt
            dfs(it.first,vis,mini,adj);
        }
    }   
}
    int minScore(int n, vector<vector<int>>& roads) {
        //1 se n tak jane me min edge ka wt
        //There is at least one path between 1 and n
        // = min wt of the graph
        unordered_map<int, vector<pair<int,int>>> adj; //u-> (v1,wt1), (v2,wt2), ..
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt}); //undirected grph
        }
        vector<int> vis(n+1,0);
        int mini = 1e9;
       
            if(!vis[1]){
                dfs(1,vis,mini,adj);  //pass by reference
        }
        return mini;
    }
};