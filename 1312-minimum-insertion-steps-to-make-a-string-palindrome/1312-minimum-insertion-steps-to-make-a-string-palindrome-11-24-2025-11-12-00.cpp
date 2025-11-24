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
int tabulation(string &s1, string &s2){
    int n = s1.length();

    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //0 rhega 0th row and 0th col me

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] +1; //diagonally
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
        }
    }
    return dp[n][n];
}
    int minInsertions(string s) {
        //3 problems -> min insertion, min insertinon and deletion -> lcs pattern
        //min replace,insetion, deletion -> dp on strings
        //mbadm   mbm
        //mdabm
        string s1 = s;
        reverse(s.begin(), s.end());

        if(s1 == s) //already a palindrome
            return 0;  

        vector<vector<int>> dp(s1.length(), vector<int>(s.length(), -1));

        // int len_of_lcs = lcs(s1,s,0,0, dp);

        int len_of_lcs = tabulation(s1,s);
        return s1.length() - len_of_lcs;
    }
};