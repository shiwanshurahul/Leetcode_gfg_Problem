class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //room1 khula hai = src
        //us room ki chabhi usse pehle aani chahiye
        //directed graph
        int V = rooms.size();
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<V;i++){
            for(auto it: rooms[i]){   //reverse order me store
                adj[i].push_back(it);   //directed isliye adj[i].push_back(it) ni krenge
            }
        }
        // for(auto it: rooms){
        //     adj[it[0]].push_back(it[1]);   //undirected me it[1] pe it[0] push_back krte
        // }

        //check for cycle: toposort
        //cycle me jo nodes hai ->unka indegree 0 ni hoga = queue me ni aanege kvi
        
        vector<int> indegree(V,0);
        int cnt = 0;

        for(int i=0;i<V;i++){
            for(auto it: adj[i]){   //indegree nikal lo har node ki
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){  //traversing over the neighbors
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }    //cycle me jo nodes hai ->unka indegree 0 ni hoga

        return cnt==V ? true : false;
         
    }
};