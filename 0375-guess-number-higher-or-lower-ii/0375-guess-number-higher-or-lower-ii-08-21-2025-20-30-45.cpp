class Solution {
public:
int solve(int start, int n, vector<vector<int>> &dp){
    if(start>=n)
        return 0;

    if(dp[start][n] != -1)
        return dp[start][n];

    int maxi = 1e9;
    
    for(int i=start;i<=n;i++){
        maxi = min(maxi, i + max(solve(start, i-1,dp), solve(i+1,n, dp)));  //inhi dono range me ho skta ans
    }

    return dp[start][n] = maxi;    
}
    int getMoneyAmount(int n) {
     //b.s laga skte but min amnt of money ka guarantee ni   
     // [1,2,3,4,5,6, .., n]
     // x is guessed -> wrong hai then
     // ans is in x+ [1,x-1] or [x+1, n] -> recursive call
     //let's say n=5, tmne sare no ek ek krke guess kre
     //1 -> a1, 2 -> a2, 3 -> a3, 4 -> a4, 5 -> a5
     //min(a1,a2,a3,a4,a5) is your ans 

     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));   
     return solve(1,n, dp);
    }
};