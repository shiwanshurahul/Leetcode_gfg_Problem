class Solution {
public:
int dp[101][101][201];
int solve(int i,int j,int k, string &s1, string &s2, string &s3){
    if(k >= s3.length() && i>= s1.length() && j>= s2.length())
        return 1;

    if(  ( k >= s3.length() ) && (i<s1.length() || j< s2.length()) )  //ek v string reh gya
        return 0;

    if(dp[i][j][k] !=-1)
        return dp[i][j][k];

    bool a = 0;
    bool b = 0;

    if(s1[i] == s3[k])
        a = solve(i+1,j,k+1,s1,s2,s3);

    if(s2[j] == s3[k])
        b = solve(i,j+1,k+1,s1,s2,s3);

    return dp[i][j][k] = a || b;   //ek v true  -> 1 || 0 = 1
}
    bool isInterleave(string s1, string s2, string s3) {
      if(s1.length() + s2.length() != s3.length())
        return 0;
        
        memset(dp, -1, sizeof(dp));

        return solve(0,0,0,s1,s2,s3);
    }
};