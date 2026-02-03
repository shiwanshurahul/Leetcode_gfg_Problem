class Solution {
public:
int solve(int i, int j, int n, int m, vector<vector<char>> &matrix, vector<vector<int>> &dp){
    if(i >= n || i<0 || j>=m || j<0)
        return 0;

    if(matrix[i][j] =='0')
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];    

    int right = solve(i,j+1, n,m, matrix, dp);
    int down = solve(i+1, j, n,m, matrix, dp);
    int diagonal = solve(i+1, j+1, n, m, matrix, dp);
 
    return dp[i][j] = 1 + min(right, min(down, diagonal));   //har i=1 pe check kr rhe for square     
}
    int maximalSquare(vector<vector<char>>& matrix) {
        //len chahiye
        //square->i =1 pe go to right, down, diagonal -> 1 + min(right, sown, diagonal)
        // 1 + bcz matrix[i][j] pe hai toh 1 len toh hai

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m,-1));

        for(int i=0;i< n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1')
                    ans = max(ans, solve(i,j, n, m, matrix, dp));
            }
        }
        return ans*ans;  //area of squ
    }
};