class Solution {
public:
int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    if(j >= t.length())     //i jahan v ho tab
        return 1;

    if(i >= s.length() && j< t.length())  //no subsequence found
        return 0;

    if(dp[i][j] !=-1)
        return dp[i][j];    

    if(s[i]==t[j])    //ra i=b bbit    ra j=b bit
        return dp[i][j] = solve(s,t, i+1, j+1, dp) + solve(s,t, i+1,j, dp);  //-> dusra subseqeunce dhundho from s
    else
     //   return solve(s,t, i, j+1) + solve(s,t, i+1,j);  // -> ye toh lcs ka hai to find longest subsequence -> tmko toh pura t chahiye s me 
        return dp[i][j] = solve(s,t, i+1,j, dp);    //no j+1 as t ke sare idx hone hai
}
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return solve(s,t, 0,0, dp);
    }
};//choice hai ki agagr matching hai toh i+1,j+1 ya i+1,j as dono alag ans dega