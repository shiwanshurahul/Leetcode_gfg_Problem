class Solution {
public:
int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp){
    if(i >= nums.size())
        return 0;

    if(prev !=-1 && dp[i][prev+1] !=-1 )
        return dp[i][prev+1];

    int a = 0;
    int b = 0;

    if(prev == -1 || nums[i] > nums[prev]){
        a = 1 + solve(nums,i+1,i, dp);   //1 len added
        b = solve(nums,i+1,prev, dp);   //choice of dp
    }
    else{
        b = solve(nums,i+1,prev, dp);    
    }

    return dp[i][prev+1] = max(a,b);    

}
    int lengthOfLIS(vector<int>& nums) {
        //famous type

        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solve(nums,0,-1, dp);
    }
};