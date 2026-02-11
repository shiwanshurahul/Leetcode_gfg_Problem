class Solution {
public:
int M = 1e9 + 7;
typedef long long ll;
typedef pair<ll,int> p;  //{dist,node}
    int countPaths(int n, vector<vector<int>>& roads) {
        //0 to n-1 in shortest time in unidrected grap
        //no of ways not the time takn is askd
        //wt is positive (t)
        // = djkstra = single src to all nodes ka shortest path
        //nbr ke via smaller path khojt

        unordered_map<int, vector<pair<int,int>>> adj;
        //u-> {v1,t1}, {v2,t2}
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});  //undirecte
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<ll> dist(n,1e12); //initialy
        vector<ll> cnt(n,0);
        //src to 0 jane ka shortest path ka cnt
        //src to 1 jane ka via shortest path ka cnt
        //src to n-1 via shortest patj ka cnt

        dist[0] = 0; //src to src is 0
        pq.push({0,0});  //dist,node
        cnt[0] = 1;

        while(!pq.empty()){
            ll dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){    //vector<pair<int,int>>
                int adj_node = it.first; //u-> {v1,t1}, {v2,t2}
                int t = it.second;
                if(dist[adj_node] > t + dis){ //smaller hai via nbr
                    dist[adj_node] = t + dis;
                    pq.push({dist[adj_node],adj_node});
                    cnt[adj_node] = cnt[node];
                }
                else if(dist[adj_node] == t + dis){
                    cnt[adj_node] =(cnt[adj_node]%M + cnt[node]%M)%M;
                }
            } 
        }
        return cnt[n-1]%M; //dist[n-1] gives u min no of time
        //but tmhe nikaln hai no of ways jisse tm shortes time me
        //pahuncho 

    }
};