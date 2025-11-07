class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
            return 0;

        unordered_map<int, vector<int>> adj; //vector me indexes hoga
        //kis no ka bus ka idx(route) kya hai -> 1->0, 2->0, 7->0,1
        //idx/route ke via bfs
        //multi src ho skta
        for(int i=0;i<routes.size();i++){
            for(auto it: routes[i]){
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> vis(501,0);
        for(auto it: adj[source]){ //mark the idxs as vis
            vis[it] = 1;
            q.push(it);
        }

        int level = 1;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                int route_idx = q.front();
                q.pop();
                for(auto it: routes[route_idx]){  //array me chk
                    if(it==target)
                        return level;
                    for(auto it1: adj[it]){
                        if(!vis[it1]){
                            vis[it1] = 1;
                            q.push(it1);
                        }
                    }    
                }
            }
            level++;
        }
        return -1;

    }
};