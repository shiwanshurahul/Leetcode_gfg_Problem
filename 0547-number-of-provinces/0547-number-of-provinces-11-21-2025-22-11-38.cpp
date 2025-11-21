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
void bfs(unordered_map<int, vector<int>>& adj, int i, vector<int> &vis){
        queue<int> q;
        q.push(i);
        vis[i]=1;   //mark visited

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    return;
}       

    int findCircleNum(vector<vector<int>>& isConnected) {
        //no of connected components
        //matrix diya hai = graph/ adj list banao
        // 1 1 0
        // 1 1 0
        // 0 0 1

        int n = isConnected.size();
        unordered_map<int, vector<int>> adj; //or vector<int> adj[n]; // -> push_back same hi hoga dono me

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){  //1 ke adj me 1 kyu push kroge 
                    adj[i].push_back(j);   //undirected graph hai
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n+1,0);
        int cnt = 0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(adj,i,vis);  //jitni bar chlega utna cnt/province
        //         cnt++;       // ek traversal me apne sare connected neighbors ko mark kr dega 
        //     }
        // }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,i,vis);  //jitni bar chlega
                cnt++;
            }
        }       

        return cnt;
    }
};