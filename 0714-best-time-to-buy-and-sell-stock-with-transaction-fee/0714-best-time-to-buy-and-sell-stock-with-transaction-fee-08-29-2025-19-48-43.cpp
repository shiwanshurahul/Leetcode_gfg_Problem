class Solution {
public:
int solve(vector<int>& profit, int i, int prev, int fee, vector<vector<int>> &dp){
    if(i>= profit.size())
        return 0;

    if(dp[i][prev] != -1)
        return dp[i][prev];

    int sell = 0;
    int not_sell = 0;

    if(profit[i] > profit[prev]){
        sell = profit[i]- profit[prev] - fee + solve(profit,i+2,i+1,fee, dp);
        not_sell = solve(profit,i+1,prev,fee, dp);  //dp choice -> is profit pe ni bechna
    }
    else {   //loss = profit[i] < profit[prev]
        not_sell = solve(profit,i+1,i,fee, dp); //dono badha do  prev = i
    }

    return dp[i][prev] = max(sell, not_sell);    
}
    int maxProfit(vector<int>& prices, int fee) {

        // vector<vector<int>> dp(prices.size(), vector<int>(prices.size(),-1));
     
        // return solve(prices,1,0,fee, dp); //1st day for buying
        //tle

        int profit = 0;
        int sell = 0;
        int profit_buy_diff = -prices[0];
        for(int i=1;i<prices.size();i++){
            sell = max(sell, prices[i]+profit_buy_diff - fee);
            profit_buy_diff = max(profit_buy_diff, sell - prices[i]);
        }
        return sell;

    }
};