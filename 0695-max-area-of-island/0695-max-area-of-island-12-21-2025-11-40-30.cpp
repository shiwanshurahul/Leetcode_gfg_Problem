class Solution {
public:
int n,m;
int dfs(int i, int j, vector<vector<int>>& grid){
    if(i<0 || j<0 || i>=n || j>=m)
        return 0;

    if(grid[i][j]==0)   //0 -> already vis
        return 0;   

    grid[i][j]=0;  //mark visited    

    int up = dfs(i+1,j,grid);
    int down = dfs(i-1,j,grid);
    int right = dfs(i,j+1,grid);
    int left = dfs(i,j-1,grid);

    return 1 + up + down + left + right;    
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //max area of island
        n = grid.size();
        m = grid[0].size();
        int max_area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int cnt = dfs(i,j,grid);
                    max_area = max(max_area,cnt);
                }
            }
        }
        return max_area;
    }
};