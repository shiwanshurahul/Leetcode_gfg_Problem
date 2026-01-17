class Solution {
public:
int dp[102][102][102];
const int M = 1e9 + 7; 
int solve(int i, int curr_profit, int people, int n, int minProfit, vector<int>& group, vector<int>& profit){
    if(people>n)
        return 0; //aur peopl ni le skte

    if(i>=group.size()){
        if(curr_profit>= minProfit)
            return 1;  //1 way mila
        return 0;   //out of bound   
    } 

    if(dp[i][people][curr_profit] != -1)
        return dp[i][people][curr_profit];

    int take = solve(i+1,min(curr_profit + profit[i], minProfit),people+ group[i], n,minProfit,group,profit);

    int skip = solve(i+1,curr_profit,people,n,minProfit,group,profit);

    return dp[i][people][curr_profit] = (take%M + skip%M)%M;  
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        //curr_profit + profit[i] bhejne se out of bound error aayega as already 3-d dp hai = min(curr_profit + profit[i],minProfit) bhejo
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
    } //n is max people
};