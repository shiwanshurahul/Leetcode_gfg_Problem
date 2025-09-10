class Solution {
public:
//graph is adj list itself toh don't need to create adj list
//here, input graph is already storing each node’s neighbor = adj list hi hai

//rule:
// If input is edge list → you construct adjacency by pushing i -> it (and it -> i if undirected).
// If input is already adjacency list →  use it directly or create adjList jisme bs i -> it push_back hoga for directed and undirected both
//agar input me length chnage ho rha 1,2,3,.. toh adj list hai
//agar const 1,2,3 len hai toh construct adj list
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //room1 khula hai = src
        //us room ki chabhi usse pehle aani chahiye
        //bfs/dfs marlo agar ek v unvisited mila toh false

        //[[1,3],[3,0,1],[2],[0]]]  -> 0->1,3; 1->3,0,1; 2->2; 0->0
        
        int V = rooms.size();
        // unordered_map<int, vector<int>> adj; 
        //seedha rooms pass kr skte as wo adj ke form me hi hai
        
        // for(int i=0;i<V;i++){
        //     for(auto it: rooms[i]){  
        //         adj[i].push_back(it);   //->bas ye alloweed hai
        //         adj[it].push_back(i);    //->wrong since duplicacy aaegi
        //     }
        // }

        vector<int> vis(V,0);
        // dfs(0,rooms,vis);  //sare khulne chahiye 
            bfs(0,rooms,vis);
        //check if ek v unvisited hai toh return false
        for(int i=0;i<V;i++){
            if(!vis[i])
                return false;
        }
        return true;
         
    }
    void dfs(int i, vector<vector<int>>& rooms, vector<int>&vis){
        
        vis[i] = 1;  //mark  as visited
        for(auto it: rooms[i]){  //traverse over the neighbors
            if(!vis[it])
                dfs(it,rooms,vis);
        }
        return;        
    }
    void bfs(int i, vector<vector<int>>& rooms, vector<int>& vis){
        queue<int> q;
        vis[i] = 1;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: rooms[node]) {  //traversing over the neighbors
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
};