class Solution {
public:
//2 cost = edges hai = adj list banao
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //a,b -> b pehle lena pdega = directed edge 
        unordered_map<int, vector<int>> adj;
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);  //directed edge
        }

        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        int courses = 0;
        while(!q.empty()){
            int node = q.front();
            courses++;
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        return courses == numCourses;

    }
};