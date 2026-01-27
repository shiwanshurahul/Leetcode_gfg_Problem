class Solution {
public:
typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        //min(6,3+2*1) = 5
        //dono tarag edge bana do and djikstra lga do
        unordered_map<int,vector<pair<int,int>>> adj;
        //idhar vector<pair<int,int>> isliye hota bcz there can be multiple adj nodes
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(n,1e9);

        dist[0] = 0; //src to src is 0
        pq.push({0,0}); //dist, src

        while(!pq.empty()){
            int dis = pq.top().first;
            int node =  pq.top().second;
            pq.pop();
          
            for(auto it: adj[node]){  //pair me hai {v,wt}
                int adjNode = it.first;
                int wt = it.second;
                if(dist[adjNode] > dis + wt){ //nbr ke via jao
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[n-1] == 1e9 ? -1 : dist[n-1];
    }
};