class Solution {
public:
int solve(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
    if(target == 0)  //1 combination mila
        return 1;
        
    if(i>= nums.size() || target<0)
        return 0;

    if(dp[target][i] != -1)
        return dp[target][i];

    int pick = solve(nums,target-nums[i],0, dp);  //firse pick kr skte from start
    int skip = solve(nums,target,i+1, dp);

    return dp[target][i] = pick + skip;    //no of possible combination/ways bata rha

}
    int combinationSum4(vector<int>& nums, int target) {
        //combination me cnt ni req hai toh 1 + solve(..) ki no need
        vector<vector<int>> dp(target+1, vector<int>(nums.size(),-1));
        return solve(nums,target,0, dp);
    }
};