class Solution {
public:
int solve(vector<int> &prices, int k, int i, int prev,  vector<vector<vector<int>>> &dp){
    if(i>= prices.size() || k == 0)  //0 hote return k<=0 de skte
        return 0;

    if(dp[i][prev][k] != -1)
        return dp[i][prev][k];

    int sell = 0;
    int not_sell = 0;

    if(prices[i] > prices[prev]){   // && k!=0 laga skte but base case me handle kr rhe
        sell = prices[i] - prices[prev] + solve(prices,k-1,i+2,i+1,dp);
        not_sell  = solve(prices,k,i+1,prev, dp);  // dp choice -> is profit pe ni bechna
    }
    else { // prices[i] < prices[prev] = loss
         not_sell = solve(prices,k,i+1,i, dp);  //dono badha do
    }

    return dp[i][prev][k] = max(sell, not_sell);    
}
int solve1(vector<int> &prices, int i, bool buy, int k, vector<vector<vector<int>>> &dp){
    if(i>= prices.size() || k<=0)  //k<=0
        return 0;

    if(dp[i][buy][k] != -1)
        return dp[i][buy][k];

    if(buy){  //allowed 
        int buy_kiya = -prices[i] + solve1(prices,i+1,false,k, dp);
        int skip = solve1(prices,i+1,true,k, dp);  //buy kr skte
        return dp[i][buy][k] = max(buy_kiya,skip);
    }   
    else { //buy is not allowed
        int sell = prices[i] + solve1(prices,i+1,true,k-1, dp); 
        int skip = solve1(prices,i+1,false,k, dp);   //no buy
        return dp[i][buy][k] = max(sell,skip);
    }    
    return -1;
}
    int maxProfit(vector<int>& prices) {
        //at most 2 transactions = 3-d dp, 2-d dp pe error
        // vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(prices.size()+1,vector<int>(3,-1)));
        // return solve(prices, 2, 1, 0, dp); //pehle din buy
        //memory level exceeded

        //m-2: memory optimized
         vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2,vector<int>(3,-1)));
         return solve1(prices,0,true,2,dp); //buy is true for 1st index

    }//buy pe negative pe add hota    -> buy pe k-1 ni hoga jb buy and sell dono ho tb hoga
    //sell pe +ve me add
};
//dp: har idx pe buy and sell kr skte = explore both
// buy-> buy, skip
// sell -> sell, skip