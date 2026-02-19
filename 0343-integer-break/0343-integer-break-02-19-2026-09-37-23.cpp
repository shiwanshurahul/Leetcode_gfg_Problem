class Solution {
public:
int dp[59];
int solve(int n){
    if(n == 1)
        return 1;  //aur break ni hog

    if(dp[n] != -1)
        return dp[n];

    int ans = -1e9;
    for(int i=1;i<n;i++){  //n-1 tk
        int prod = i * max(n-i, integerBreak(n-i));
        ans = max(ans,prod);
    }
    return dp[n] = ans;
}
    int integerBreak(int n) {
        //k >= 2   
        //i, n-i -> fir ye n-i v break ho skta
        // = max(i*(n-i)), or max( i *solve(n-i))
        //further recursn
        // = i * max(n-i, solve(n-i))
        //e.g. 10 -> i=3 = i* max(7, solve(7))
        memset(dp,-1, sizeof(dp));
        return solve(n);
    }  

};