class Solution {
public:
typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //without k stop shortest chahiye toh djikstra lagao
        //idhar shortest ni based on k stops chahiye
        vector<int> dist(n,1e9);
        //edges with given wt = adj list banao {u,v,wt} -> 3 parametres
        unordered_map<int, vector<pair<int,int>> >adj; //or vector<vector<pair<int,int>>> adj(n);
         //idhar vector<pair<int,int>> isliye hota bcz there can be multiple adj nodes
        for(vector<int> &it : flights){ 
            int u =it[0];
            int v =it[1];
            int cost =it[2];
            adj[u].push_back({v,cost});   //u -> {v1,wt1}, {v2,wt2}
        }
        // priority_queue<p,vector<p>,greater<p> >pq;  //min heap
        queue<p> q;  //isse v bneg
        q.push({0,src});  //dist,noe
        dist[src] = 0;
        
        int level = 0;  //level ka track
        while(!q.empty() && level <=k){  //as per quest
            int N = q.size();
            while(N--){
                int dis = q.front().first;
                int node = q.front().second;
                q.pop();
                for(auto it: adj[node]){  // {v1,wt1}, {v2,wt2}
                    int nbr = it.first;  //pair
                    int nbr_wt = it.second;
                    if(dis + nbr_wt < dist[nbr]){
                        dist[nbr] = dis + nbr_wt;
                        q.push({dist[nbr], nbr});
                    }
                }
            }
            level++;
        }
        return dist[dst] == 1e9 ?  -1 : dist[dst];
    }
};