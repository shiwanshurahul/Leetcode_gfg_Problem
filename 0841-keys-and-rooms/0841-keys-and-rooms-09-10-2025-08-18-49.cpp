class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //room1 khula hai = src
        //us room ki chabhi usse pehle aani chahiye
        //bfs/dfs marlo agar ek v unvisited mila toh false

        //[[1,3],[3,0,1],[2],[0]]]  -> 0->1,3; 1->3,0,1; 2->2; 0->0
        
        int V = rooms.size();
        unordered_map<int, vector<int>> adj;
        //seedha rooms pass kr skte as wo adj ke form me hi hai
        
        for(int i=0;i<V;i++){
            for(auto it: rooms[i]){  
                adj[i].push_back(it); 
            }
        }

        vector<int> vis(V,0);
        dfs(0,adj,vis);  //sare khulne chahiye 

        //check if ek v unvisited hai toh return false
        for(int i=0;i<V;i++){
            if(!vis[i])
                return false;
        }
        return true;
         
    }
    void dfs(int i, unordered_map<int,vector<int>>& adj, vector<int>&vis){
        
        vis[i] = 1;  //mark  as visited
        for(auto it: adj[i]){  //traverse over the neighbors
            if(!vis[it])
                dfs(it,adj,vis);
        }
        return;        
    }
};