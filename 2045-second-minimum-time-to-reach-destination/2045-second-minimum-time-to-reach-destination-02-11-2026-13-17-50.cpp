class Solution {
public:
typedef long long ll;
typedef pair<ll,int> p;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //undirected, no cycle
        //The time taken to travers any edge is time minutes.
        //chnage mins ke bad change hoga signal and initally 1 pe green hai = u got change min at 1 to travsers before u stop for change min and this process continues
        //return 1 to n tk jane me second smallest tim

        // -> once u start tm mid me rk ni skte, u can only stop at vertex : see e.g. min time = 6, second min = 13

        //single src to all nodes ka min time = djikstr
        //idhar 2nd min chahiy = keep 2 dist arr

        //change ka dhyan rkho ki avi rukna hai ya ja skte
        // Run Dijikstra and limit your search of each node to twice
        // (rather than the usual once visited). Store two best 
        //minimums to read a node in two different arrays.

        // Trafic ligh logic is easy if (ta/change) is even => green
        // or else red signal.
        vector<ll> dist1(n+1,1e9);  //min
        vector<ll> dist2(n+1,1e9);  //second min
        unordered_map<int,vector<pair<int,ll>>> adj;
        //u -> {v1,wt1}, {v2,wt2}
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int t = time;

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});  //undirected
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        dist1[1] = 0;  //1 based idx
        pq.push({0,1});

        while(!pq.empty()){
            ll dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if( (dis/change)%2 == 1)  //odd = Red
                dis += (change-dis%change);

            for(auto it: adj[node]){ //{v1,t1}, {v2,t2}
                int adj_node = it.first;
                ll t = it.second;
              
                if(dist1[adj_node] > t + dis ){
                    dist2[adj_node] = dist1[adj_node]; //dist2 me second min
                    dist1[adj_node] = t + dis;
                    pq.push({t+dis,adj_node});
                }
                else if(dist2[adj_node] >  t + dis && dist1[adj_node] != t + dis ){
                    dist2[adj_node] = t + dis;
                    pq.push({t+dis, adj_node});
                }
               
            }
        }
        for(auto it: dist2){
            cout<<it<<endl;
        }
        return dist2[n];


    }
};