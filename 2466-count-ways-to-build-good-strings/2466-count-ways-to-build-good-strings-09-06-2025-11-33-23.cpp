class Solution {
public:
int M = 1e9 +7;
int solve(int low, int high, int zero, int one, int len, vector<int> &dp){
    if(len > high)
        return 0;

    if(dp[len] !=-1)
        return dp[len];

    int ans = 0;

    if(len>= low && len<=high)
        ans++;    //1 good string mila -> don't return 1

    ans +=  solve(low,high,zero,one, len+zero, dp);   
    ans += solve(low,high,zero,one, len+one, dp);

    return dp[len] = ans %M;     
}
    int countGoodStrings(int low, int high, int zero, int one) {
        //total zero,one ni har bar zero 0 and one 1 dal skte
        vector<int> dp(100001,-1);
        return solve(low, high, zero, one, 0, dp);
    }
};