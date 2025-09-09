class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //directed graph-> kahn algorithm ->indegree=0 pe q me push (incoming edges)  -> bfs
        //terminal -> no outgoing edges
        //safe node -> terminal node || jis v node pe hai uske sare paths terminal nodes pe khatam
        //cycle me fans gya = not a terminal node = not safe 
        //cycle me jitne v nodes hai wo not safe hai

        //= avi indegree of terminal nodes can be 0 toh traversal pura ni kr pa rha
        // = reverse krdo edges = ab traverse kr skte 
        // cycle walo ki indegree 0 hoti hi ni = queue me ni aenge kvi

        int V = graph.size();   //or n
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<V;i++){
            for(auto it: graph[i]){   //reverse order me store
                adj[it].push_back(i);   //directed isliye adj[i].push_back(it) ni krenge
            }
        }

        //toposort:
        queue<int> q;
        vector<int> indegree(V,0);
        vector<int> ans;

        for(int i=0;i<V;i++){    //get indegree of all nodes
            for(auto it: adj[i]){
                indegree[it]++;
            }
        } 

        for(int i=0;i<V;i++){      //indegree =0 ko q me push
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){  //traversing neighbors
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;



    }
};