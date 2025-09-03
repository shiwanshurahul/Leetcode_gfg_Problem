class Solution {
public:
int dp[201][1001];
int solve(int i,vector<int>& nums, int target){
    int n =nums.size();
    if(target==0)
    return 1;
    if(i>=n || target<0)
        return 0;
        if(dp[i][target]!=-1)
        return dp[i][target];
    int include_index =solve(0,nums,target-nums[i]); //start from index 0 when including index 
    int exclude =solve(i+1,nums,target);

    return dp[i][target] = include_index +exclude;
}
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
                return solve(0,nums,target);  
    }
};