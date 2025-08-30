class Solution {
public:
int solve(vector<int> &prices, int i, int prev, int k, vector<vector<vector<int>>> & dp){
    if(i>= prices.size() || k==0)  //k <=0 likh skte
        return 0;

    if(dp[i][prev][k] !=-1)
        return dp[i][prev][k];

    int sell = 0;
    int not_sell = 0;

    if(prices[i] > prices[prev]){
        sell = prices[i] - prices[prev] + solve(prices,i+2,i+1,k-1, dp);
        not_sell = solve(prices,i+1,prev,k, dp); //is profit pe ni bechna
    }
    else {  // loss = prices[i] < prices[prev] 
        not_sell = solve(prices,i+1,i,k, dp);  //i, prev dono badha do
    }

    return dp[i][prev][k] = max(sell, not_sell);    
}
int solve1(vector<int> &prices, int i, bool buy, int k, vector<vector<vector<int>>> &dp){
    if(i>= prices.size() || k ==0)   // or k<=0  
        return 0;    

    if(dp[i][buy][k] !=-1)
        return dp[i][buy][k];

     if(buy){
        int buy = -prices[i] + solve1(prices,i+1,false, k, dp);
        int skip_buy = solve1(prices,i+1,true,k, dp);

        return max(buy, skip_buy); 
     }
     else {   //no buy
        int sell = prices[i] + solve1(prices,i+1,true,k-1, dp);
        int skip = solve1(prices,i+1,false,k, dp);

        return dp[i][buy][k] = max(sell, skip);
     }   
     return -1;  //never executed
}
    int maxProfit(int k, vector<int>& prices) {
        //at most k transactions
        //3-d dp
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(prices.size()+1,vector<int>(k+1,-1)));
        // return solve(prices, 1, 0, k, dp); // pehla ko buy -> lis jaisa
        //memory level exceeded

        //m-2: har idx pe 2 option -> buy, sell = dono explore with dp

        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solve1(prices,0,true,k, dp); //0th ko buy 
    }
};