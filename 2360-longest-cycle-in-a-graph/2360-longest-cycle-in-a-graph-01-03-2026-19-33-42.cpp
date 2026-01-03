class Solution {
public:
int ans = -1;
void dfs(int node, vector<int>&edges, unordered_map<int,int> &dist, vector<int>& vis){
    vis[node] = 1;
    int nbr = edges[node];
    if(nbr != -1 && !vis[nbr]){  //not visited
        dist[nbr] = dist[node] + 1;
        dfs(nbr,edges,dist,vis);
    }
    else if(nbr != -1 && vis[nbr]){
        ans = max(ans, dist[node] - dist[nbr] +1 );
    }

}
    int longestCycle(vector<int>& edges) {
        //at most 1 outgoing edge = adj list me max 1 hi aa skta
        // = no need of adj list 
        // = a node can max form/participate in 1 cycle only
        int n = edges.size();
        vector<int> vis(n,0);
        unordered_map<int,int> dist;  //len of cycle
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dist[i] = 1;
                dfs(i,edges,dist,vis);
            }
        }
        return ans;
    }
};