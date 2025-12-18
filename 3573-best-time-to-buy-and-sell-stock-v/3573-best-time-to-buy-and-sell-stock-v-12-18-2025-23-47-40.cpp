class Solution {
public:
typedef long long ll;
int n;
ll dp[1001][501][3];
ll solve(vector<int>&prices, int k, int i, int CASE){
      if(i>= n || k==0){
        if(CASE==0)  //complet hai
            return 0;
        return -1e9;    
      }
      if(dp[i][k][CASE] !=-1)
        return dp[i][k][CASE];

      ll take = 0;
      ll skip =0; 
      if(CASE==0){  //2no case explore
        take = max( (-prices[i] + solve(prices,k,i+1,1)),
                    (prices[i] + solve(prices,k,i+1,2 )) );
        skip = solve(prices,k,i+1,0);
      }
      else if(CASE==1){  //sell krke normal transaction complt kro
        take = prices[i] + solve(prices,k-1,i+1,0);
        skip = solve(prices,k,i+1,1);   //aage becho is profit pe mt becho 
      }
      else{  //buy kro shortsell wala transactn complete
        take = -prices[i] + solve(prices,k-1,i+1,0);
        skip = solve(prices,k,i+1,2); //aage buy kroge is pe mt buy
      }
    return dp[i][k][CASE] = max(take, skip);  
      
}
    long long maximumProfit(vector<int>& prices, int k) {
        //ek bar me Normal trans complete hoga ya Short selling wala
        //3 cases: 0 -> max(normal me buy, Short me sell) -> corrspond 2 ya 3 call hoga
        // 1 -> sell kr rhe (normal transact complet)
        //2 -> buy kr rhe (Short selli complet ho rha)
        n = prices.size();
        int CASE = 0;  //0,1,2
        memset(dp,-1,sizeof(dp));
        return solve(prices,k,0,CASE);
    }//last me complet rkho transactio aisa ni hoga ki Short sell kiya but buy se phle  i>=n
};