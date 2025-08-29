class Solution {
public:
//express i and j for base case
//explore all possible cases
//return max, min, sum, ..
int solve(vector<int> &prices, int i, int prev, vector<vector<int>> &dp){
    if(i>= prices.size())
        return 0; //no buying selling ab

    if(dp[i][prev] !=-1)
        return dp[i][prev];

    int not_sell = 0;  //aur profile ka dekh rhe
    int sell = 0;
    int cant_sell = 0;  //loss

    if(prices[i]> prices[prev]){
        sell = prices[i]- prices[prev] + solve(prices,i+3,i+2,dp);  //cooldown
        not_sell = solve(prices,i+1,prev, dp);     //jyada profit tb becho
    }
    else {  //prev > i = loss      -> 3rd var bana skte can't_sell but isse ho jayega
        not_sell = solve(prices,i+1, i, dp);
    }

    return dp[i][prev] = max(not_sell,sell);    

}
    int maxProfit(vector<int>& prices) {
        //1 din ka cooldown period
        //marzi hai ki jyada profit pe beche
        //lis jaisa

        vector<vector<int>> dp(prices.size()+1, vector<int>(prices.size()+1, -1));
        return solve(prices,1,0,dp);    //pehle ko buy kr rhe
    }
};