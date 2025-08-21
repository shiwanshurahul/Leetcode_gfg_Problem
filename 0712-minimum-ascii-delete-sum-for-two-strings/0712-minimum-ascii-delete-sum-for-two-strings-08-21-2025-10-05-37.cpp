class Solution {
public:
int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i>= s1.length() || j>= s2.length())
        return 0;   

    if(dp[i][j] !=-1)
        return dp[i][j];

    if(s1[i] == s2[j])   //1 len/match found
        return dp[i][j] = int(s1[i]) + lcs(i+1, j+1, s1, s2, dp);  //len of lcs ke jagah ascii ke basis pe
    else
        return dp[i][j] = max(lcs(i,j+1,s1,s2, dp), lcs(i+1,j,s1,s2, dp));    
        
}
    int minimumDeleteSum(string s1, string s2) {
        //lcs lelo
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        int len = lcs(0,0,s1,s2, dp);

        int char_sum=0;
        for(auto it: s1){
            char_sum+= it;
        }
        for(auto it: s2){
            char_sum += it;
        }
        return char_sum - 2*len;
    }
};