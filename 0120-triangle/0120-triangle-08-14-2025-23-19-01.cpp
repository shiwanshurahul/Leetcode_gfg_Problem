class Solution {
public:

int solve(vector<vector<int>> & triangle, int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i == n-1 )
        return triangle[i][j];    //include this in sum

    if(i> n-1 || i< 0 || j> i || j<0)   //ith se jyada ni hoega kisi v row(n) me
        return 1e9;

    if(dp[i][j] !=1e9)
        return dp[i][j];

    int down_same_i = triangle[i][j] + solve(triangle, i+1, j, n, m, dp);
    int down_adj = triangle[i][j] + solve(triangle, i+1, j+1, n, m, dp);

    return dp[i][j] = min(down_same_i, down_adj);        
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m =1; //1st row me 1 col
        // vector<vector<int>> dp;
        // for(int i=0;i<n;i++){
        //     int col_size = triangle[i].size();
        //     vector<int> col(col_size,1e9);
        //     dp.push_back(col);
        // }   or                              yes can't fill with -1
        vector<vector<int>> dp(n+1, vector<int>(n+1,1e9));

        return solve(triangle, 0, 0, n, 1, dp);
    }
};