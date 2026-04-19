class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //directed graph
        //cycle wale nodes ka indegree 0 ni hoga = q me never push
        unordered_map<int, vector<int>> adj;  
        // or vector<vector<int>> (n);
        // u -> {v1,v2, ..}
        vector<int> indegree(numCourses,0);
        
        for(auto it: prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a); //b pehle lena hoga a lene ke liye
            indegree[a]++;  //b->a ja rha
        }  
        
        queue<int> q;
        vector<int> ans;
        int cnt=0;

        // for(int i=0;i<numCourses;i++){
        //     for(auto it: adj[i]){
        //         indegree[it]++; //bcz it->i ja rha
        //     }
        // }
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