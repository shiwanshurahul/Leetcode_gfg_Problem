class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //edges with wt diya hai = adj list banao
        unordered_map<int, vector<pair<int,int>>> adj;
        //or vector<vector<pair<int,int>>> adj(n)
        // adj[node] = { {neighbor, weight}, {neighbor2, weight2}, ... }
            // e.g. for 2 -> {1,1}, {3,1}
        for(auto &it: times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        //dijkstra -> nbr ke via min dist ki kosis
         //dijkstra is single src to each node ka min duration
    //Note: dist me store hai src se har node jane ka distance  e.g. src=0
    //0-0 jane ka dist, 0-1 jane ka dist, 0-2 jane ka dist

         int src=k;
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         vector<int> dist(n+1, 1e9);  //since min chhaiye
         
         dist[k] = 0;     //k to k distance is 0
         pq.push({0, k});    //dist, node as dist ke basis pe sort in heap

         while(!pq.empty()){   //heap ka
            int dis = pq.top().first;
            int node = pq.top().second;   //us node tak ka distatnce from 0/src 
            pq.pop();
            for(auto it: adj[node]){   //u -> {v1, w1}
                int adjNode  = it.first;    //adj list me aise hai-> {node,node_weight}
                int edge_weight = it.second;
                if(dis + edge_weight < dist[adjNode]){   //node + nbr_wt
                    dist[adjNode] = dis + edge_weight;
                    pq.push({dist[adjNode], adjNode});
               }
            }
        }
        //dist bhar chuka hai with min
        int max_val = -1e9; 
        for(int i=1;i<=n;i++){
            max_val = max(max_val, dist[i]);  //max val of dist
        }

        return max_val == 1e9 ? -1 : max_val;
    }
};