class Solution {
public:
int solve(vector<int>&coins, int i, int amount, vector<vector<int>> &dp){
    if(i>= coins.size() || amount <0)
        return 0;

    if(amount==0)
        return 1;  //1 way/combination mila jisse amount bna

    if(dp[i][amount] !=-1)
        return dp[i][amount];

    int pick = solve(coins,i,amount-coins[i], dp); //yahan 1 + ni bcz no of steps/coins used ni pucha
    int skip = solve(coins,i+1,amount, dp);        

    return dp[i][amount] = pick + skip;
}
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1,-1));
        return solve(coins,0, amount, dp);
    } // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

        // Why this happens (core concept)
        // When a function returns, execution resumes exactly after the function call line in the same stack frame.
    //simple recursion me v aisa hota
};