class Solution {
public://jump game jaisa
int solve(vector<int> &nums, int i, vector<int> &dp){
    if(i>=nums.size()-1)
        return 0;  //add 0 and return no of jumps

    if(dp[i] !=-1)
        return dp[i];

    int temp = 1e9;  //har recursive call ka apna temp

    for(int j=1;j<=nums[i];j++){
        temp = min(temp, 1 + solve(nums,i+j, dp));   
    }
  return dp[i] = temp;

}
    int jump(vector<int>& nums) {
        //min no of jumps 

        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0, dp);  
    }// recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
};// solve(0) -> solve(i=1) -> solve(i=2) -> solve(i=3) -> solve(i=4) -> return 0
//sbka i se initallly call jaega fir sbka j chlega and min aega