class Solution {
public:
int n = 0;
int solve(int i,int col,vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(i<0 || i>=n || col<0 || col>=n)
        return 1e9;

    if(i==n-1)
        return grid[n-1][col];  //jis v col pe ho

    if(dp[i][col] !=-1)
        return dp[i][col]; 

    int ans = 1e9;
    for(int nextcol=0;nextcol<n;nextcol++){
        if(nextcol !=col)  //toh hi call kr
            ans = min(ans, grid[i][col] + solve(i+1,nextcol,grid,dp));
    }
    return dp[i][col] = ans;        
}
int tabulation(vector<vector<int>>& grid){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //recursin ke opposite dirn me likht
    //so, recursn me next row pe ja rhe the toh idhar piche row se fill
    //dp[i][j] -> min falling path sum when you choose row=i to n-1
    // and col j to n-1 

    for(int i=0;i<n;i++){  //0th row ko same fill
        dp[0][i] = grid[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int mini = 1e9;  //each
            for(int k=0;k<n;k++){
                if(k !=j)
                    mini = min(mini, grid[i][j] + dp[i-1][k]);
            }
            dp[i][j] = mini;
        }
    }

    int ans = 1e9; //find min in last row
    for(int i=0;i<n;i++){
        ans = min(ans, dp[n-1][i]); 
    }
    return ans;

}
    int minFallingPathSum(vector<vector<int>>& grid) {
        //same col se ni lo next
        //adjacent ho -> koi v aa skta neeche other than same col
        //e.g. min(i-1,j-2; i-1,j-1; i-1,j+1; i-1,j+2; i-1,j+3;..)
        // = for loop me call recursin for next
        //optio -> dp
        n = grid.size();
        // int ans = 1e9;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // for(int col=0;col<n;col++){  //0th row ke sare cols se dekh lo
        //     ans = min(ans, solve(0,col,grid,dp));
        // }  
        //memoizatin ke bad v tle -> n*n*n with dp
     
        // return ans;
        return tabulation(grid);
    }
};