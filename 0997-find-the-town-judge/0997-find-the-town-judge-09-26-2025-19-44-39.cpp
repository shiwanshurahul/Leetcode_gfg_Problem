class Solution {
public: //fixed 2 side = edges hai = adj list banao
    int findJudge(int n, vector<vector<int>>& trust) {
        //[a,b] = a trusts b = directed graph
        //judge trusts nobody = no edges towards him
        //cycle hoga toh un nodes ka indegree kvi 0 hoga hi ni 
        // = queue me ni aaenge kvi
        //outdegree me sari edges town judge pe aaengi = n-1 edges on him
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);

        unordered_map<int, vector<int>> adj;
            for(auto it: trust){
                adj[it[0]].push_back(it[1]);
                indegree[it[1]]++;  //ja rha 1,2
                outdegree[it[0]]++;  //aa rha 3,3
            }
        
         for(int i=1; i<n+1; i++) {
            if(indegree[i]== n-1 && outdegree[i]==0)
                return i;
        }
        return -1;

       



    }
};