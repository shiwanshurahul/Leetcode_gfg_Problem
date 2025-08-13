class Solution {
public:
//express i and j for base case
//explore all possible scenarios
//return min, max, sum, ..
    int solve(vector<vector<int>> &grid, int n, int m, int i,int j, vector<vector<int>> &dp){
        if(i== n-1 && j == m-1)
            return grid[i][j]; //sum me curr add krke store   
        if(i > n-1 || i<0 || j> m-1 || j<0)
            return 1e9;

        if(dp[i][j]!=-1)
            return dp[i][j];    

        int right = grid[i][j] + solve(grid, n, m, i, j+1,dp);  //add curr and go to right
        int down = grid[i][j] + solve(grid, n, m, i+1, j,dp);
        
        return dp[i][j] = min(right, down);        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n,m, 0,0, dp);
    }
};