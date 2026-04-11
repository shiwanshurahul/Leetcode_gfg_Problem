class Solution {
public:
int solve(vector<int>& nums, int i, vector<int> &dp){
    if(i>= nums.size()-1)
        return 1;

    if(dp[i] !=-1)
        return dp[i];

    for(int j=1;j<=nums[i];j++){
        if(solve(nums,i+j,dp))
            return dp[i] = 1; 
    } 

    return dp[i] = 0;     //last me if true ni mila toh

}
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums,0, dp);
    }
    // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
};