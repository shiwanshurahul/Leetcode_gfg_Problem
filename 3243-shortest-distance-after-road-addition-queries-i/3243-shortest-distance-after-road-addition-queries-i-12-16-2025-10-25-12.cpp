class Solution {
public:
typedef pair<int,int> p;
int dijkstra(vector<vector<pair<int,int>>> &adj, int n){

    priority_queue<p, vector<p>, greater<p> >pq;
    vector<int> dist(n,1e9);

    pq.push({0, 0}); //dist, src
    dist[0] = 0;  //src to src is 0
    
    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            int nbr = it.first;
            int nbr_wt = it.second;
            if(d + nbr_wt < dist[nbr]){  //is nbr k respect me check
                dist[nbr] = d + nbr_wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }
    
    return dist[n-1];
}
int bfs(vector<vector<int>> &adj, int n){
    queue<int> q;
    vector<int> vis(n,0);

    q.push(0);
    vis[0] = 0;
    int level = 0;

    while(!q.empty()){
        int N = q.size();
        while(N--){
            int node = q.front();
            q.pop();
            if(node == n-1)
                return level;
            //is node ke sare nbr daldo and check ki koi n-1 hai
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }    
        }
        level++;
    }
    return -1;
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        //dijkstra -> weighted graph chahiye (edge wt)
        //single src to all node -> har nbr ka min dist nikalo
        //here, 1 lelo sbme
        // vector<vector<pair<int,int>>> adj(n);
        // //u :{v1,wt1}, {v2,wt2}, ..
        // for(int i=0;i<=n-2;i++){
        //     adj[i].push_back({i+1,1}); 
        // }
        // vector<int> ans;
        // for(auto it: queries){
        //     int u = it[0];
        //     int v = it[1];
        //     adj[u].push_back({v,1});  //update adj list
        //     ans.push_back(dijkstra(adj, n));
        // }
        //m-2: bfs

        vector<vector<int>> adj(n); 

        for(int i=0;i<=n-2;i++){
            adj[i].push_back(i+1);  //u-> v
        }
        vector<int> ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            ans.push_back(bfs(adj,n));
        }
          

        return ans;

    }
};