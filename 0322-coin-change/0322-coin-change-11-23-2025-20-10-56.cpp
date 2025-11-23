class Solution {
public:
int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
    if(amount==0)
        return 0;  //1 way mila -> add 0 and return -> already no of coins ka cnt rkh rhe

    if(amount<0 || i>= coins.size())
        return 1e9;  //min chahiye toh return 1e9

    if(dp[i][amount] !=-1)
        return dp[i][amount];

    int pick = 1 + solve(coins,amount-coins[i],i, dp);  //1 coin used
    int skip = solve(coins, amount,i+1, dp);

    return dp[i][amount] = min(pick, skip);

}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
        int num = solve(coins,amount,0, dp);
        return num == 1e9 ? -1 : num; 
    }
};