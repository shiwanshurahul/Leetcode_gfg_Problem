class Solution {
public:
int solve(string &text1, string &text2, int i,int j, vector<vector<int>> &dp){
    if(i>= text1.length() || j>= text2.length())
        return 0;  //add 0 to sum and return

    if(dp[i][j] !=-1)
        return dp[i][j];

    if(text1[i] == text2[j])
        return dp[i][j] = 1 + solve(text1,text2,i+1,j+1,dp);
    else
        return dp[i][j] = max(solve(text1,text2,i+1,j, dp), solve(text1,text2,i,j+1, dp));         

}
int tabulation(string &text1, string &text2){
    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));  //oth row and col 0 rkho
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(text1[i-1]==text2[j-1])  
                dp[i][j] = 1 + dp[i-1][j-1];  //diagonal
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  
        }
    }
    return dp[n][m];

}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // return solve(text1, text2, 0,0,dp);

        return tabulation(text1,text2);
    }
};