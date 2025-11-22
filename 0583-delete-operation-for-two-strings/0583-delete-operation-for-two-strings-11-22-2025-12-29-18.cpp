class Solution {
public:
int solve(string &word1, string &word2, int i,int j, vector<vector<int>>& dp){
    if(i>= word1.length() || j>= word2.length())
        return 0; //add 0 to sum and return

    if(dp[i][j] !=-1)
        return dp[i][j];

    int a=0,b=0;

    if(word1[i]==word2[j]){
        a = 1 + solve(word1,word2,i+1,j+1, dp);
    }
    else {
        b = max(solve(word1,word2,i,j+1,dp), solve(word1,word2,i+1, j, dp));
    }

    return dp[i][j] = max(a,b);

}
    int minDistance(string word1, string word2) {
        //lcs nikal do and baki char - 2*lcs

        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,-1));
        int len_lcs = solve(word1,word2,0,0, dp);

        return word1.length() + word2.length() - 2*len_lcs;

    }
};