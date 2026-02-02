class Solution {
public:
int n,m;
void dfs(int i,int j, vector<vector<int>> &grid){
    if(i<0 || j<0 || i>=n || j>=m)
        return;

    if(grid[i][j]!=1)   //ya 0 ya 3
        return;    

    grid[i][j] = 3;  //mark visited -> 0 se v kr skte

    dfs(i+1,j,grid);   //possible recursive call to neighbors
    dfs(i-1,j,grid); 
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);    
}
    int numEnclaves(vector<vector<int>>& grid) {
        //1 -> land, 0 -> sea
        //bahar se connected hai toh mark krdo
        n = grid.size();
        m = grid[0].size();

        //sare wall/boundaries pe check krlo and mark visited

        //0th row:
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)
                dfs(0,i,grid);
        }

        //n-1th row:
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1)
                dfs(n-1,i,grid);
        }

        //0th col:
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                dfs(i,0,grid);
        } 

        
        //m-1th col:
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1)
                dfs(i,m-1,grid);
        }

        //cnt the no of 1
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    cnt++;
            }
        }

    return cnt;


    }
};