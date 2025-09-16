class Solution {
public:
queue<pair<int,int>> q;
int n,m;
void dfs(int i,int j, vector<vector<int>>& grid){

    if(i<0 || j<0 || i>=n || j>= m )
        return;

    if(grid[i][j]!=1)   //can be 0 or 2
        return;

    grid[i][j] = 2;   //mark visited -> 1 v kr skte
    q.push({i,j});

    dfs(i+1,j, grid);   //recursive calls to possible neighbors
    dfs(i-1,j, grid);
    dfs(i,j-1, grid);
    dfs(i,j+1, grid);       
}
    int shortestBridge(vector<vector<int>>& grid) {
        //0 1 0    1-> land, 0-> water; 2 islands hai
        //0 0 0    o/p -> 1 
        //0 0 1

        //smallest no -> bfs
        // multiple src, multiple destination == no dijkstra
        // dfs +bfs ->1st island pe dfs se visited mark kro and q me push i,j jb grid[i][j] = 1 on pura island
        // taki uske sare parts se min dist calc kre second island ka
        n = grid.size();
        m = grid[0].size();
        int flag = 0;  //1st island se
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !flag){
                    flag = !flag; 
                    dfs(i,j, grid);
                    break;
                }
            }
            if(flag)
                break;
        }

        //ab dusra island tak ka shortest path nikalo using bfs 
        int level = 0;  //traditional bfs on matrix
        while(!q.empty()){
            int N = q.size();  //curr level ka size
            while(N--){  //curr level pe traverse in all nbr
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(grid[i][j]==1) //second island mila
                    return level;
    
                //explore the nbrs of that level
                if(i-1 >= 0 && grid[i-1][j] !=2){
                    if(grid[i-1][j] == 1) 
                        return level;
                    grid[i-1][j] = 2;   //mark visited
                    q.push({i-1, j});
                        
                }
                if(i+1 < n && grid[i+1][j] !=2){
                    if(grid[i+1][j] == 1) 
                        return level;
                    grid[i+1][j] = 2; //mark visited 
                    q.push({i+1, j});   
                }
                if(j-1 >= 0 && grid[i][j-1] !=2){
                    if(grid[i][j-1] == 1)
                        return level;
                    grid[i][j-1] = 2;   //mark visited
                    q.push({i, j-1});
                }
                if(j+1 < m && grid[i][j+1] !=2){
                    if(grid[i][j+1] == 1) 
                        return level;
                    grid[i][j+1] = 2;    //mark visited
                    q.push({i, j+1});
                }  
            }
            level++;  //ek level khatam
        }

        return level;
    }//We start by finding the first island using a DFS approach. We traverse the grid until we find the first cell with a value of 1, indicating the start of the island.
    // Once we find the first island, we mark all the visited cells in a set to keep track of them.
    // Next, we use a BFS approach starting from the visited cells of the first island. We explore the neighboring cells and check if they are part of the second island or not.
    // We continue BFS until we find the second island or exhaust all possible cells.
    // By using BFS, we can ensure that we find the shortest bridge between the two islands, as we traverse the grid layer by layer.
    // The distance (level) of each layer in the BFS represents the shortest path from the first island to the second island.
};