class Solution {
public:
int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp){
    if(i >= nums.size())
        return 0;

    if(prev !=-1 && dp[i][prev+1] !=-1 )
        return dp[i][prev+1];

    int take = 0;
    int skip = 0;

    if(prev == -1 || nums[i] > nums[prev]){
        take = 1 + solve(nums,i+1,i, dp);   //1 len added
        skip = solve(nums,i+1,prev, dp);   //choice of dp
    }
    else{
        skip = solve(nums,i+1,prev, dp);    
    }

    return dp[i][prev+1] = max(take,skip);    

}
    int lengthOfLIS(vector<int>& nums) {
        //famous type

        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solve(nums,0,-1, dp);
    }
};