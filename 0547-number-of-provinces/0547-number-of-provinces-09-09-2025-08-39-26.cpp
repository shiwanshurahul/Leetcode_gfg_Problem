class Solution {
public:
void dfs(unordered_map<int, vector<int>>& adj, int i, vector<int> &vis){
    vis[i] = 1;  //mark visited -> node v name rkh skte 
    
    for(auto it: adj[i]){   //traverse to connected neighbors
        if(!vis[it])
            dfs(adj,it,vis);   
    }
    return;    //ni v likhoge toh chlega

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        //no of connected components
        //matrix diya hai = graph/ adj list banao
        // 1 1 0
        // 1 1 0
        // 0 0 1

        int n = isConnected.size();
        // vector<int> adj[n];
        unordered_map<int, vector<int>> adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){  //1 ke adj me 1 kyu push kroge 
                    adj[i].push_back(j);   //undirected graph hai
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n+1,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);  //jitni bar chlega utna cnt/province
                cnt++;       // ek traversal me apne sare connected neighbors ko mark kr dega 
            }
        }

        return cnt;
    }
};