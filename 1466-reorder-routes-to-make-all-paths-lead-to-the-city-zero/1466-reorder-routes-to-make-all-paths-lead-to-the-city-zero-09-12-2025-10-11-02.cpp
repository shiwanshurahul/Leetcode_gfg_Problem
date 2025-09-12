class Solution {
public:
int cnt = 0;
//2 nodes const = edges hai
    int minReorder(int n, vector<vector<int>>& connections) {
        //problem is root se traverse kro agar ja skte kisi v node pe toh cnt++ and node se root ka v edge bana do
        //node to zero jana hai e.g. 1->0, 3->1, 5->4
        //agar root se traversal start kiya toh kuch nodes visit ni hoega like 2,4
        // = khud se edges bana do = har node pe ja skte root se  
        
        // unordered_map<int, vector<pair<int,int>>> adj;
        // for(int i=0;i<n;i++){
        //     for(auto it: connections){
        //         adj[it[0]].push_back({it[1],1});  //original edge
        //         adj[it[1]].push_back({it[0],0});  //tmne banaya
        //     }
        // }
        //agar original edge se ja rhe toh cnt++ and 0 wale se toh tmne traversal ke liye banaya hai

        vector<int> vis(n,0);

        // dfs(adj,vis,0);  //dfs se tle aa rha
        // bfs(adj,vis,0);     //bfs ''
        //m3: split adjlist 
        vector<vector<int>> adj(n), back(n);
        queue<int> q;
        q.push(0);
        
        for (auto c : connections){
            adj[c[0]].push_back(c[1]);
            back[c[1]].push_back(c[0]);
        }
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            vis[curr] = 1;

            // change dir for all arrows facing out
            for (auto a: adj[curr]){
                if (!vis[a]){
                    cnt++;
                    q.push(a);
                }
            }
            // push other nodes so we visit everything
            for (auto b: back[curr]){
                if (!vis[b]) q.push(b);
            }
        }
       
    
        return cnt;

    }
    void dfs(unordered_map<int, vector<pair<int,int>>>& adj, vector<int>& vis, int i){
        vis[i] = 1;  //or node -> mark visited
        for(auto it: adj[i]){  //pair hai adj me
            if(!vis[it.first]){
                int nbr = it.first;
                int check = it.second;
                if(check == 1)  //original edge hai
                    cnt++;
                dfs(adj,vis,nbr);    
            }    
        }
        return;
    }
    void bfs(unordered_map<int, vector<pair<int,int>>>& adj, vector<int>& vis, int i){
        queue<int> q;
        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &[nbr,check]: adj[node]){
                if(!vis[nbr]){
                    // int nbr = it.first;
                    // int check = it.second;
                    if(check==1)
                        cnt++;
                    q.push(nbr);
                    vis[nbr] = 1;    
                }
            }
        }
    
    
    }
};