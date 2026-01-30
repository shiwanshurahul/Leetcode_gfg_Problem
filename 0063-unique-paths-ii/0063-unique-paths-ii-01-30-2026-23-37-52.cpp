class Solution {
public:
//express i and j for base case
//explore all possible solutions
//return max, min, sum ..
int solve(vector<vector<int>> &obstacleGrid, int i,int j, int n, int m, vector<vector<int>> &dp ){
    if(i == n-1 && j == m-1 && obstacleGrid[i][j] !=1 )
        return 1;  //1 path mila

    if(i > n-1 || i< 0 || j> m-1 || j<0)
        return 0;

    if(obstacleGrid[i][j] == 1)
        return 0;  //obstacle    

    if(dp[i][j]!=-1)
        return dp[i][j];

    int down = solve(obstacleGrid, i+1, j, n, m, dp);
    int right = solve(obstacleGrid, i, j+1, n ,m, dp);  

    return dp[i][j] = down + right;  
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));

        return solve(obstacleGrid, 0, 0, n, m, dp);
    }
};