#include <climits>
class Solution {
public:
//express base case in i,j
//explore all possible cases isme v max,min le skte
//return max, min, sum..
//nice type -> typical se thora alag
int solve(vector<int> &nums, int i, int k, vector<vector<int>> &dp){
    if(k == 0) //
        return 0;

    if(i>= nums.size())
        return 1e9;     
 
    if(dp[i][k] != -1)
        return dp[i][k];

    int rob = max(nums[i], solve(nums, i+2, k-1, dp));   //k-- pe error
    int skip = solve(nums, i+1, k, dp);    

    return dp[i][k] = min(rob, skip);
}
    int minCapability(vector<int>& nums, int k) {
        //total k house are to be robbed 
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1)); //is pe tle
        return solve(nums, 0, k, dp);
    }
};