class Solution {
public:
typedef long long ll; 
int solve(vector<int>&nums, int n,int target, int i,vector<vector<int>>&dp){
    if(i>=n|| target < 0)
        return 0;

    if(target==0)
        return 1; //1 way reached

    if(dp[i][target] !=-1)
        return dp[i][target];

    ll pick = solve(nums,n,target-nums[i],0,dp);  //pick again from start
    ll skip = solve(nums,n,target,i+1,dp);

    return dp[i][target] = (int)pick + skip;

}
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return (int)solve(nums,n,target,0,dp);
    }
};