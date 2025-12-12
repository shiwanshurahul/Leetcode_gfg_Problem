class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        //jispe indegree ni hai wo return
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
            //or indegree[it[1]]++;
        }
        int ans = -1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans =i;
                cnt++;
                if(cnt>1)
                    return -1; //more than 1 have indegree as 0
            }    
        }
        return ans;
    }
};