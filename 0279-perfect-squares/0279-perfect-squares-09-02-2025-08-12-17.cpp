class Solution {
public:
    int numSquares(int n) {
        //oa me v aata
       // 12 -> 1 + 1 + .. = 12
       // 12 ->  3^2 + 1 + 1 + 1 = 4
       // 12 -> 4 + 4 + 4 = 3 = ans

       //100 -> 10^2 = 1

       //loop lelo i = 1 to n/2 take bcz max sqrt utne me aaega and sare i ko explore

       vector<int> dp(n+1,-1);
       return solve(n, dp);
    }
    int solve(int n, vector<int> &dp){
        if(n==0)
            return 0;   //ek perfect square sum mila

        if(dp[n] != -1)
            return dp[n];

        int mini = 1e9;

        // or i <= sqrt(n)
        for(int i=1;i*i<=n;i++){  //1, 4, 9, 16->No
            int temp = 1 + solve(n-i*i, dp);      //12-1, 12- 4, 12-9, ..
            mini = min(mini, temp);
        }
        return dp[n] = mini;
    } 
};