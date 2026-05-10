class Solution {
public:
// If every row has 2 numbers only → very likel an edge list. -> create an adjacency list.
//here 3 hai const = edges hai
// If row size varies (sometimes 0, sometimes many neighbors) → an adjacency list itself.

// Also check problem statement:
// If input format says “m edges follow” → edge list.
// If it gives n lines each listing neighbors → adjacency list

//rule
// If input is edge list → you construct adjacency by pushing i -> it (and it -> i if undirected).
// If input is already adjacency list →  use it directly or create adjList jisme bs i -> it push_back hoga for directed and undirected both
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
        for(auto it: adj[node]){  //nbr pe traverse
            if(!vis[it]){
                vis[it] = 1;  //mark visit
                q.push(it);   //push to q
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
        unordered_map<int, vector<int>> adj; //or vector<int> adj[n]; or vector<vector<int>> v reh skta 
        // -> teeno same hai so push_back same hi hoga teeno me

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){  //1 ke adj me 1 kyu push kroge 
                    adj[i].push_back(j); //undirectd grap ha 
                    adj[j].push_back(i); // or mp[i].push_back(j);
                }
            }
        }

        vector<int> vis(n+1,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                // dfs(adj,i,vis); // jitni bar chlega 
                bfs(adj,i,vis); // utna cnt/province
                cnt++;       // ek traversal me apne sare connectd neighbors ko mark kr dega 
            }
        }

        return cnt;
    }
};