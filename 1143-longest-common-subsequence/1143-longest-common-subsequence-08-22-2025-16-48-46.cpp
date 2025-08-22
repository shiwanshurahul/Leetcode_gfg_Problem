class Solution {
public:
//start se hi chck krte
int n,m;
// int dp[1001][1001];
// int solve(string &text1, string &text2,int i,int j){
//     //isko peeche se v la skte tb i>=0 || j>=0 condition lgega and recursive call v change
//         if(i>=n || j>=m)
//             return 0;

//        if(dp[i][j]!=-1)
//             return dp[i][j];

//         int a=0,b=0;

//         if(text1[i]==text2[j])
//             a = 1+ solve(text1,text2,i+1,j+1);
//         else 
//             b = max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));

//         return max(a,b);
// }
int tabulation(string &text1, string &text2){
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // ->[n+1][m+1] me oth row and col is 0 then return dp[n][m]

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
        }
    }

    return dp[n][m];
}

    int longestCommonSubsequence(string text1, string text2) {
        n =text1.size();
        m =text2.size();
        // memset(dp,-1,sizeof(dp));
        //return solve(text1,text2,0,0);

        //print lcs

       return tabulation(text1,text2);

        
    }
};