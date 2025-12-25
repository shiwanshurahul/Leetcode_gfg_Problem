class Solution {
public:
//express i and j for base case
// explore all possible paths as per ques
// return max, min, sum ..
// int dp[101][101];
int solve(int m, int n, int i, int j, vector<vector<int>> &dp){
    if(i== m-1 && j== n-1)
        return 1;
    if(i>m-1 || j> n-1 || i<0 || j<0)
        return 0;
    if(dp[i][j]!= -1)
        return dp[i][j];

    int right = solve(m,n, i,j+1,dp);
    int down = solve(m, n ,i+1, j,dp);  

    return dp[i][j] = right + down;       
}
    int uniquePaths(int m, int n) {
        // memset(dp, -1, sizeof(dp));
        //m = row
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m,n,0,0,dp);
    }
};