class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // start to end tk jana hai with maxim probabilit
        // wt given hai
        // = djikstr me min find krte = idhar max_heap se max lo
        // = single src to all nodes tk ka shortest path

        //give priorty to maxi probabilit path
        //multiply kro probaibilty
        
        unordered_map<int, vector<pair<int,double>>> adj;
        //u-> {v1,wt1}, {v2,wt2}
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v,wt});  //undirecte
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<double,int>> pq;  
        //max heap for max probabilty {dist,node}
        vector<double> dist(n,-1); //max probabilit store kro
                                   //so, -1 initally dalo
        dist[start_node] = 1.0; //src to src probability is 1
        pq.push({1.0,start_node}); //dist,

        double ans = 0;

        while(!pq.empty()){
            double dis = pq.top().first; //or probab
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){  //{v1,wt1}, {v2,wt2}, ..
                int adj_node = it.first;
                double wt = it.second; 

                if(dist[adj_node] < wt * dis){ //small ha dist me  
                    dist[adj_node] = wt * dis; //= max val store
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        return dist[end_node] == -1 ? 0 : dist[end_node];
    }
};