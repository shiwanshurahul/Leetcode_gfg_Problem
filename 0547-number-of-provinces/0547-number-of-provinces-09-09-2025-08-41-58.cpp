class Solution {
public:
bool dfs(int node,  vector<int> &visited,vector<int>adj[]){
        visited[node] =1;   //mark visited -> recursive call
        for(auto neighbor: adj[node]){   //apne possible neighbors pe chalao
         if(!visited[neighbor]) //adjacent nodes toh connected component
            dfs(neighbor,visited,adj);
        }
        return true;
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        //connected components nikalo
        //      1 2 3
        //
        //  1   1 1 0
        //  2   1 1 0
        //  3   0 0 1
       // matrix/graph diya hai: jis i,j pe 1 hai toh connected hai = adj list banao

       int n =isConnected.size();
       vector<int> visited(n,0);
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j ){
                    adj[i].push_back(j);    //undirected graph
                    adj[j].push_back(i);
                }
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
           if(!visited[i]){   
               dfs(i,visited,adj);   //sare connected marked ho jaenge
               cnt++;
           }
        }
        return cnt;
        
        //2 types dfs que->ek aisa aur ek flood fill/n of provinces jaisa 
        //dfs -> mark visited and then recursive call to possible neighbors -> tree me v yahi hota e.g. solve(root->left,-)
        //  solve(root->right);  and inme generally void hota return type

        //2 types dfs que->ek no of provinces(graph) aur ek flood fill(matrix) jaisa 
        //graph wale me dfs-> auto child krke recursion call to neighbors bcz sare connected ni hote and same strategy
        //matrix wale me dfs-> check ki i<=0 || i>=n || j<0 || j>=n
    }
};