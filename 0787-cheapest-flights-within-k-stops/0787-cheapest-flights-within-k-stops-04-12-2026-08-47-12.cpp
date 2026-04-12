class Solution {
public:
typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //without k stop shortes chahiy toh only djikstr lagao
        //idhar shortest ni based on k stops chahiy toh bfs ony
        //idahr tree hai toh while(N--) wala bfs
        vector<int> dist(n,1e9);
        //edges with given wt = adj list bana {u,v,wt} -> 3 parametres
        unordered_map<int, vector<pair<int,int>> >adj; 
        //or vector<vector<pair<int,int>>> adj(n);
         //idhar vector<pair<int,int>> isliye hota bcz there can be
         // multipl adj nodes -> yahi normal hot
        for(vector<int> it : flights){ 
            int u =it[0];
            int v =it[1];
            int cost =it[2];
            adj[u].push_back({v,cost});   //u -> {v1,wt1}, {v2,wt2}
        }
        //m1:priority_queue<p,vector<p>,greater<p> >q; //min heap-> ni laga skt
        queue<p> q;  //isse hi bneg -> bfs

        q.push({0,src});  //dist,node
        dist[src] = 0;
        
        int level = 0;  //level ka track
        while(!q.empty() && level <=k){  //as per ques
            int N = q.size();
            while(N--){  //-> tree 
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