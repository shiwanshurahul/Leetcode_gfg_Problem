class Solution {
public:
int solve(int i, int prev, string&s, int k, int n, vector<vector<int>> &dp){
    if(i>=n)
        return 0;

    if(dp[i][prev+1] !=-1)
        return dp[i][prev+1];

    int pick = 0;
    int skip = 0;
    if(prev == -1 || abs(s[i] - s[prev]) <= k){
        pick = 1 + solve(i+1,i,s,k,n, dp);
        skip = solve(i+1,prev,s,k,n, dp);
    }
    else{
        skip = solve(i+1,prev,s,k,n, dp);
    }    

    return dp[i][prev+1] = max(pick,skip);
}
int tabulation(string &s, int k,int n ){
    // vector<int> dp(n,1); //1-d
    // int ans = 1;
    // for(int i=0;i<n;i++){  //har i ke liye j wahan tk chle
    //     for(int j=0;j<i;j++){
    //         if(abs(s[i]-s[j]) <=k){
    //             dp[i] = max(dp[i],dp[j]+1);
    //             ans = max(ans,dp[i]);
    //         }
    //     }
    // }  //T.C -> o(n^2) = tle
    //optimize ->tm j=0 to j<i ja rhe = un 'j' pe hi jao jo abs(dp[i] <=k) ho
        // i.e for each character position i, we need to find the number of characters in the sequence ending at [s[i−k],s[i+k]] if that exist in the prefix.
        int ans = 0;
        vector<int> dp(26,0);
        for(int i=0;i<n;i++){
            int curr = s[i] -'a';
            int left = max(0,curr-k);
            int right = min(25,curr+k);
            //sirf is range me iterate
            int longest = 0;
            for(int j=left;j<=right;j++){
                longest = max(longest,dp[j]);
            }
            dp[curr] = max(dp[curr],longest+1);
            ans = max(ans,dp[curr]);
        }
        return ans;
}
    int longestIdealString(string s, int k) {
        //same as lis
        int n = s.length();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(0,-1,s,k,n,dp); //tle
        return tabulation(s,k,n);
    }
};