class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //without k stop pe djikstra lagao
        vector<int> dist(n,1e9);
        //edges with given given = adj list banao
        unordered_map<int, vector<pair<int,int>> >adj; //or vector<vector<pair<int,int>>> adj(n);
        for(vector<int> &it : flights){ 
            int u =it[0];
            int v =it[1];
            int cost =it[2];
            adj[u].push_back({v,cost});   //u -> {v1,wt1}, {v2,wt2}
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src] = 0;
        int level = 0;
        while(!q.empty() && level <=k){  //as per quest
            int N = q.size();
            while(N--){
                int node = q.front().first;
                int dis = q.front().second;
                q.pop();
                for(auto it: adj[node]){
                    int nbr = it.first;
                    int nbr_wt = it.second;
                    if(dis + nbr_wt < dist[nbr]){
                        dist[nbr] = dis + nbr_wt;
                        q.push({nbr, dist[nbr]});
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