class Solution {
public:
//edges hai since const hai 2 len ke = adj list banao
//shortest path = bfs 
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //shortest path/steps from node 0 to node x such that the 
        //edge colors alternate along the path

        //nodes ke beech me red, blue edge dono ho skta
        //same node ko dusre edge pe reuse kr skte
        //agar let's say kisi node pe alternate ni ho pa rha toh cycle bana ke try krlo bich me alternate krke warna -1
        //e.g. 0-3 -> 3 steps, 0->4 -> 7 steps 
        unordered_map<int,vector<pair<int,int>> > adj;  //vector of int ki jagah pair

        for(int i=0;i<n;i++){
            for(auto it :redEdges){
                adj[it[0]].push_back({it[1],0});  //0 for red
            }
        }

        for(int i=0;i<n;i++){
            for(auto it: blueEdges){
                adj[it[0]].push_back({it[1],1});   //1 for blue
            }
        }

        vector<vector<int>> vis(n, vector<int>(2,0));  //{neighbour, kis color se}
        //vis[i][0] ->dist from 0 to i ending with redEdge
        //vis[i][1] ->dist from 0 to i ending with blueEdge
        vector<int> ans(n,-1);

        queue<vector<int>> q;
        q.push({0,0, -1}); //node,steps, color
        vis[0][0] = 1;
        vis[0][1] = 1;
        ans[0] = 0;

        while(!q.empty()){
            auto elem = q.front(); 
            int node = elem[0];
            int steps = elem[1];
            int prev_color = elem[2];
            q.pop();
            for(auto it: adj[node]){   //it[0] -> visited hai ya ni, it[1] konse color se
                int nbr_node = it.first; int nbr_color = it.second;
                if( !vis[nbr_node][nbr_color] && nbr_color != prev_color){  //unvisited
                    vis[nbr_node][nbr_color] = 1;
                    q.push({nbr_node, steps+1 ,nbr_color});  //or it
                    if(ans[nbr_node] == -1)
                        ans[nbr_node] = 1 + steps;
                }
            }
        }    
    
        return ans;
    }
};