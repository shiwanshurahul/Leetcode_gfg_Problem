class Solution {
public:
vector<vector<int>> ans;
//change ho rha graph - adj list given
void dfs(vector<vector<int>>&graph, int i, vector<int>&vis, int n, vector<int>temp){
    vis[i] = 1;
    temp.push_back(i);

    if(i==n)
        ans.push_back(temp);

    for(auto it: graph[i]){
        if(!vis[it])
            dfs(graph,it,vis,n,temp);
    }

    vis[i] = 0;  //backtrack taki dusra path dhund ske
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //to n-1 ka sara path in DAG = toposort
        int n = graph.size();
        vector<int> vis(n,0);
        
        vector<int> temp;
        dfs(graph,0,vis,n-1,temp); //target

        return ans;
        
    }
};