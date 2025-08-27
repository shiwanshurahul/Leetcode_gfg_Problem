class Solution {
public:
int n,m;
void dfs(int i, int j, vector<vector<int>> &grid){
    if(i<0 || i>=n || j<0 || j>=m)
        return;

    if(grid[i][j] != 1)
        return;

    grid[i][j] = '!';
                   
    dfs(i+1,j,grid);         //call to possible neighbours
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
}
    int numEnclaves(vector<vector<int>>& grid) {
        //jo v boundary se touched hai wo rhega and baki 1 jo andar me hai unka count
        
        //check 4 boundaries
        n = grid.size();
        m = grid[0].size();

        //0th row
        for(int i=0;i<m;i++){
            if(grid[0][i] ==1)
                dfs(0,i,grid);
        }

        //last row
        for(int i=0;i<m;i++){
            if(grid[n-1][i] ==1)
                dfs(n-1,i,grid);
        }

        //0th col
        for(int i=0;i<n;i++){
            if(grid[i][0] ==1)
                dfs(i,0,grid);
        }

        //last col
         for(int i=0;i<n;i++){
            if(grid[i][m-1] ==1)
                dfs(i,m-1,grid);
        }

        //jo internal 1 hai unka cnt is ans 
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1)
                    cnt++;
            }
        }

        return cnt; 

    }
};