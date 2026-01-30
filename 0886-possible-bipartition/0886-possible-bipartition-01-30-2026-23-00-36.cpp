class Solution {
public:
bool bfs(vector<int>&vis, int i, unordered_map<int, vector<int>>& adj){
    queue<int> q;

    vis[i] = 1;
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(vis[it] == -1){   //unvisited
                vis[it] = !vis[node];
                q.push(it);
            }    
            else if(vis[it] == vis[node]){
                return false;
            }    
        }
    }
    return true;
}
bool dfs(vector<int>&vis, int i, unordered_map<int, vector<int>>& adj){
   
    vis[i] = 1;
    for(auto it: adj[i]){
        if(vis[it] == -1){  //unvisited
            vis[it] = !vis[i]; 
            if(!dfs(vis,it,adj) )
                return false;
        }     
        else if(vis[it] == vis[i]){
            return false;   
        }    
    }
    return true;
}

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //bipartition = 2 grp me divide
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n+1,-1); //1 to n
        //1 ya 0 se color kro
        //undirected bcz dono hate krte ek dusre ko
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]);
        }

        for(int i=1;i<n+1;i++){
            if(vis[i] == -1 ){  //uncolored
                if(!bfs(vis,i,adj))
                    return false;
            }
        }
        return true;
    }
};