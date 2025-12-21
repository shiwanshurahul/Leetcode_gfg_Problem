class Solution {
public:
typedef long long ll;
void dfs(int node, vector<int>&vis, ll &cnt, vector<vector<int>>& adj){
    vis[node] = 1;
    cnt++;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(it,vis,cnt,adj);
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        int nodes_remaining = n; //initally n
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);  
            adj[it[1]].push_back(it[0]);  //undirected graph
        }
        vector<int> vis(n,0);

        ll ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ll cnt=0;
                dfs(i,vis,cnt,adj);  //pass by reference

                ans += cnt * (nodes_remaining - cnt);
                nodes_remaining = (nodes_remaining - cnt);
            }
        }
        return ans;
    }
};