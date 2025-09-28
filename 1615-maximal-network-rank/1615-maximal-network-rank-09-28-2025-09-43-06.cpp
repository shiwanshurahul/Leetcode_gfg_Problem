class Solution {
public:// 2 = edges = adj list banao
bool check_direct_connection(int idx1, int idx2, unordered_map<int, vector<int>>&adj){
    for(auto it: adj[idx2]){
        if(it==idx1)
            return true;
    }
    return false;
}
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);  //indegree and outdegree yahi hai
        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);  //undirected graph
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        //direct adj list me v it->second ka 2 max nikal lo  -> all pairs bola hai but direct connection me 1 hi count hoga
        
        //maximum pair nikal do
        // for(int i=0;i<n;i++){
        //     for(auto it: adj[i]){
        //         indegree[it]++;
        //     }
        // }
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int i_rank = adj[i].size(); //itne neighbors of i
                int j_rank = adj[j].size();  //or indegree v le skte

                int rank = i_rank + j_rank;
                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) //j exists in adj list of i
                    rank--;  //direct edge b/w i and j = 2 bar add ho rha
                maxi = max(maxi,rank);    
            }
        }
        return maxi;

    }  //check_direct_connection v use kr skte in place of find
};