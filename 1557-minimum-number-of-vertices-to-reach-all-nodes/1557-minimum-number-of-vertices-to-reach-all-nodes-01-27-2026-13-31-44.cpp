class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //dag
        //jiska v incoming 0 hai wo alag se aaega
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);  //0->1 = 1 ka indegree
            indegree[it[1]]++;
        }
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};