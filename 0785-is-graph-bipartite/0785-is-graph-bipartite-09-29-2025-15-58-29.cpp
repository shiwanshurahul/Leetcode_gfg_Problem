class Solution {
public:
bool bfs(int i, vector<int>&vis, vector<vector<int>>& adj){
    queue<int> q;
    q.push(i);
    vis[i] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop(); 
        for(auto it: adj[node]){
            if(vis[it]==-1){
                vis[it] = !vis[node];  //apne nbr ka opposite
                q.push(it);
            }    
            else if(vis[it] == vis[node]){  //already marked with same color as nbr
                return false;
            }    
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        //undirected graph
        //2 different color se color krdo -> parent wala ni
    //    unordered_map<int, vector<int>> adj;
    //     for(auto it: graph){  //-> adj hi de rkha hai = edges size is changing
    //         adj[it[0]].push_back(it[1]);
    //         // adj[it[1]].push_back(it[0]);
    //     }
        int V = graph.size();
        vector<int> vis(V,-1);   // 0 or 1 se color krne ka try
       
        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if( !bfs(i,vis,graph) )  //false aaya toh
                    return false;
            }    
        }        
        return true;
        
    }
};