class Solution {
public:
int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
    if(amount==0)
        return 0;  //1 way mila -> add 0 and return -> alread no of coins ka cnt rkh rhe

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
    } // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

    // Why this happens (core concept)
    // When a function returns, execution resumes exactly after the function call line in the same stack frame.
    //simple recursion me v aisa hota
};