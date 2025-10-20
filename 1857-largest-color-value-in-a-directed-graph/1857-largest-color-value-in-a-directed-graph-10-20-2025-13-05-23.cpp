class Solution {
public:
//edges hai = adj list banao
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        //sbka color diya hai -> color[0] = 0th node ka color, color[1] = 1st node ka color, ..
        //max freq of a color in a path return
        //directed graph de rkha
        //ordering is imp -> toposort -> indegree 0 ko q me push
        //sare u,v ka color ko store in dp table
        //dp[no of nodes][colors]
        //dp[0][a] -> 0 pe 'a' se kitne khatam ho rhe, dp[2][b] -> 2 pe 'b' se kitne khatam hue
        int N = colors.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(N,0);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);  //undirected
            indegree[it[1]]++;    // 0->1 hai toh 1 ki indegree
        }
        queue<int> q;
        vector<vector<int>> dp(N, vector<int>(26,0));

        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
                dp[i][colors[i]-'a'] = 1;
            }
        }

        int ans = 0;
        int cnt_of_nodes = 0;  //cycle check krne ke liye -> jo nodes cycle me hoenge unka indegree 0 ni hoga = never pushed to q
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt_of_nodes++;
            ans = max(ans, dp[node][colors[node]-'a']);
            for(auto it: adj[node]){
                for(int i=0;i<26;i++){  //sare 26 color ka check
                    dp[it][i] = max(dp[it][i], dp[node][i] + (colors[it]-'a' == i)); //agar i color ka hai
                }
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(cnt_of_nodes < N)  //cycle
            return -1;
        return ans;    
    }
};