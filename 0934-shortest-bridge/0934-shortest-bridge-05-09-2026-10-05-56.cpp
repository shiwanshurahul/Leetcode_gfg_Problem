class Solution {
public:
queue<pair<int,int>> q;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool is_valid(int i,int j){
    if(i<0 || i>= n || j<0 || j>=m)
        return 0;
    return 1;    
}
void dfs(int i,int j, vector<vector<int>>& grid){

    if(i<0 || j<0 || i>=n || j>= m )
        return;

    if(grid[i][j]!=1)   //can be 0 or 2 -> alread vis or 0
        return;

    grid[i][j] = 2;   //mark visited -> 1 v kr skte
    q.push({i,j});   //1 wale all in q -> island ke sare cells ko visited mark krke store

    dfs(i+1,j, grid);   //recursiv calls to possible neighbors
    dfs(i-1,j, grid);
    dfs(i,j-1, grid);
    dfs(i,j+1, grid);       
}
    int shortestBridge(vector<vector<int>>& grid) {
        //1 1 0    1-> land, 0-> water; 2 islands hai
        //0 1 0    o/p -> 1 
        //0 0 1

        // smalles no -> bfs
        // multi src bfs
        // multipl src, multiple destinatio == no dijkstra
        // dfs +bfs ->1st island ko dfs se visited mark kro and q me push i,j jb grid[i][j] = 1 on pura island
        // ab uske sare parts se min dist calc kre second island ka
        n = grid.size();
        m = grid[0].size();
        int flag = 0;  //1st island se
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !flag){
                    flag = !flag; 
                    dfs(i,j, grid);   //1st island marked
                    break;
                }
            }
            if(flag)
                break;
        }
            //check alread marked before pushing in queue 
        //ab dusra island tak ka shortet path nikalo using bfs 
        int level = 0;   //traditional bfs on matrix
        while(!q.empty()){
            int N = q.size(); //curr level ka size
            while(N--){  //curr level p traverse in all nbr
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                    
                // grid[i][j] = 2;  //mark visited  -> duplicacy hota isliye q me push ke sath hi krdo
                //explore the nbrs of this level
                for(auto it: dirn){
                    int i_ = i + it[0];
                    int j_ = j + it[1];
                    if(is_valid(i_,j_) && grid[i_][j_] !=2){ //not visited
                        if(grid[i_][j_] == 1)  //2nd island mila
                            return level;
                        q.push({i_,j_});
                        grid[i_][j_] = 2;  //mark visited 
                    }  
                }
            }
            level++;  //ek level khatam
        }

        return level;  
    }//We start by finding the first island using a DFS approach. We traverse the grid until we find the first cell with a value of 1, indicating the start of the island.
    // Once we find the first island, we mark all the cells of that island visited to keep track of them.
    // Next, we use a BFS approach starting from the visited cells of the first island. We explore the neighboring cells and check if they are part of the second island or not.
    // We continue BFS until we find the second island or exhaust all possible cells.
    // By using BFS, we can ensure that we find the shortest bridge between the two islands, as we traverse the grid layer by layer.
    // The distance (level) of each layer in the BFS represents the shortest path from the first island to the second island.
};