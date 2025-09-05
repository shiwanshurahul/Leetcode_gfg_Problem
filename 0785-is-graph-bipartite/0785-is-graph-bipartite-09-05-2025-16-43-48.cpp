class Solution {
public:
bool bfs(int i, vector<vector<int>>& graph, vector<int>& color){
    queue<int> q;
    q.push(i);
    color[i] =0; //mark visited
                
    while(!q.empty()){
        int node =q.front();
        q.pop();
        for(auto it: graph[node]){ //node ke neighbors pe iterate
            if(color[it] == -1){   //unvisited
                color[it] = 1- color[node];
                q.push(it);
            }    //same color in neighbors = not bipartite
            else if(color[it]==color[node]){
                return false;
            }
        }
    }

    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
       //graph is adjacency list   
       //no cycle  = bipartite
       int V = graph.size();
       vector<int> color(V,-1); //0 v le skte
	     
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){  //unvisited
	        if(bfs(i,graph,color)==false)
	            return false;
	        }
	    }
	    return true;
	}
};


