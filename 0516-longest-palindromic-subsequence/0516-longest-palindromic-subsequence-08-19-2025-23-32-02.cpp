class Solution {
public:
int lcs(string &s1, string &s2, int i,int j, vector<vector<int>> &dp){
    if(i >= s1.length() || j>= s2.length())
        return 0;

    if(dp[i][j] !=-1)
        return dp[i][j];    

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(s1,s2, i+1,j+1, dp);
    else
        return dp[i][j] = max(lcs(s1,s2,i+1,j, dp), lcs(s1,s2,i,j+1, dp));     
}
    int longestPalindromeSubseq(string s) {
     //lcs nikal lo of string with its reverse
     string s1 = s;
     reverse(s.begin(), s.end());

     vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
     return lcs(s1,s,0,0, dp);   
    }
};
