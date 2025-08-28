class Solution {
public:
int lcs(string &s1, string &s2, int i,int j, vector<vector<int>> &dp){
    if(i >= s1.length() || j>= s2.length())
        return 0;

    if(dp[i][j] !=-1)   
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 +  lcs(s1,s2,i+1,j+1, dp); //1 len add
    else       
        return dp[i][j] = max(lcs(s1,s2,i+1,j, dp), lcs(s1,s2,i,j+1, dp));
}
    int minInsertions(string s) {
        //mbadm   mbm
        //mdabm
        string s1 = s;
        reverse(s.begin(), s.end());

        if(s1 == s) //already a palindrome
            return 0;  

        vector<vector<int>> dp(s1.length(), vector<int>(s.length(), -1));

        int len_of_lcs = lcs(s1,s,0,0, dp);
        return s1.length() - len_of_lcs;
    }
};