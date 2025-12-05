class Solution {
public:
typedef pair<int,int> pi;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //without k stop shortest chahiye toh djikstra lagao
        //idhar shortest ni based on k stops chahiye
        vector<int> dist(n,1e9);
        //edges with given wt = adj list banao {u,v,wt}
        unordered_map<int, vector<pair<int,int>> >adj; //or vector<vector<pair<int,int>>> adj(n);
        for(vector<int> &it : flights){ 
            int u =it[0];
            int v =it[1];
            int cost =it[2];
            adj[u].push_back({v,cost});   //u -> {v1,wt1}, {v2,wt2}
        }
        priority_queue<pi,vector<pi>,greater<pi> >pq;
        pq.push({0,src});
        dist[src] = 0;
        int level = 0;
        while(!pq.empty() && level <=k){  //as per quest
            int N = pq.size();
            while(N--){
                int dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                for(auto it: adj[node]){
                    int nbr = it.first;
                    int nbr_wt = it.second;
                    if(dis + nbr_wt < dist[nbr]){
                        dist[nbr] = dis + nbr_wt;
                        pq.push({ dist[nbr], nbr});
                    }
                }
            }
            level++;
        }
        if(dist[dst]==1e9)
            return -1;
            return dist[dst];
    }
};