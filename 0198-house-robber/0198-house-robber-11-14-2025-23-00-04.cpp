class Solution {
public:
//edge cases in terms of i and j
//explore all possible cases as per question
//return max, min, sum ..
int dp[101];
int solve(vector<int> &nums, int i){
    if(i>= nums.size())
        return 0;
    if(dp[i]!=-1)
        return dp[i];    
    int take = nums[i] + solve(nums, i+2);
    int skip = solve(nums,i+1);

    return dp[i] = max(take, skip);    
}
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};