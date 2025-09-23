class Solution {
public:
int n,m;
void dfs(int i, int j, vector<vector<char>>& grid){
    if(i<0 || j<0 || i>=n || j>=m)
        return;

    if(grid[i][j]!='1')  //already visited  -> !grid[i][j]=='0' && !grid[i][j]=='2'
        return;

    grid[i][j]='2';

    dfs(i+1,j,grid);    //recursive call to possible neighbors
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);

}
    int numIslands(vector<vector<char>>& grid) {
        //1 -> land

        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){   //land
                    dfs(i,j,grid);
                    cnt++;  //sare connected components visit krdo
                }
            }
        }
        return cnt;
    }
};