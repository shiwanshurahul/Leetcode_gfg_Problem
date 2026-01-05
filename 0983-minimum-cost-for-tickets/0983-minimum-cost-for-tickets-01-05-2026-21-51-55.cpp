class Solution {
public:
int solve(vector<int> &days, vector<int>& costs, int i, vector<int>& dp){
    if(i>=days.size() )
        return 0;

    if(dp[i] !=-1)
        return dp[i];

    int one_day = costs[0] + solve(days,costs,i+1, dp);
    
    int j = i;  
    int max_7_day = days[i] + 7;
    while(j<days.size() && days[j] < max_7_day){ 
        j++;            //11>4, 11>6, 11>7, 11>8
    }
    int seven_days = costs[1] + solve(days,costs,j, dp);   
    
    int k = i;
    int max_30_days = days[i] + 30;
    while(k< days.size() && days[k] < max_30_days){
        k++;
    }
    int one_month = costs[2] + solve(days,costs,k, dp); //30 din bad wale pe aao
    
    return dp[i] = min({one_day, seven_days, one_month});  

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //min amount
        //costs array 3 size ka rhega
        //teeno cases explore krlo
        vector<int> dp(days.size()+1,-1);
        return solve(days, costs, 0, dp);
    
    }
};