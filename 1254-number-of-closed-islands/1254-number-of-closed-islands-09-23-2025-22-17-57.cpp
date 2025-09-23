class Solution {
public:
int n,m;
bool dfs(int i,int j, vector<vector<int>>& grid){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;

    if(grid[i][j]==1)  //ek dirn me water mila, already visited
        return true;        

    grid[i][j] = 1;    //mark visted

    //charo dirn se chahiye water
    bool down = dfs(i+1,j,grid);
    bool up = dfs(i-1,j,grid);
    bool left = dfs(i,j-1,grid);
    bool right = dfs(i,j+1,grid);
    return down && up && left && right;    
    
}
    int closedIsland(vector<vector<int>>& grid) {
        //1 -> water, 0 -> land
        //0 surrounded by 1 in all dirn -> closed island
        // = 0 se charo dirn me dfs maro and return true agar 1 hai, 0 mile toh jate rho -> (aage 1 ho skte)

        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){ 
                    if(dfs(i,j,grid))
                        cnt++;
                }        
            }
        }
        return cnt;  

    }
};