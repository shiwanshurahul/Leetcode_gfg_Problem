class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //directed graph
        //cycle wale nodes ka indegree 0 ni hoga = q me never push
        unordered_map<int, vector<int>> adj;
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]); 
        }
        
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> ans;
        int cnt=0;

        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)  //cycle walon ka indegree 0 ni hoga = never pushed to q
                    q.push(it);
            }
        }
        if(cnt == numCourses)
            return ans;
        return {};    
    }
};