class Solution {
public:
int solve(vector<int> &coins, int amount , int i, vector<vector<int>>& dp){
    if(amount==0)  //1 way mila
        return 0;

    if(amount < 0 || i>=coins.size())
        return 1e9;    

    if(dp[i][amount] !=-1)
        return dp[i][amount];

    int pick = 1 + solve(coins,amount-coins[i], i, dp);  //fir se pick kr skte
    int skip = solve(coins,amount,i+1, dp);

    return dp[i][amount] = min(pick,skip);    
}
    int coinChange(vector<int>& coins, int amount) {
        //min no of coins

        //2-d dp bcz amount and i change ho rha
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1)); 

        int ans = solve(coins,amount,0, dp);
        return ans==1e9 ? -1 : ans;  
    }
};