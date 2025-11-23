class Solution {
public:
int solve(vector<int> &nums, int i, int sum, vector<vector<int>>& dp){
    if(i>= nums.size() && sum ==0 )
        return 0;
    
    if(i>= nums.size())
        return -1e9;

    if(dp[i][sum] !=-1)
        return dp[i][sum];

    int pick = nums[i] + solve(nums,i+1,(sum+nums[i])%3, dp); 
    int skip = solve(nums,i+1,sum, dp);  
     
    return dp[i][sum] = max(pick, skip);      

}
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3,-1));
        return solve(nums,0,0, dp);
        
    }
};