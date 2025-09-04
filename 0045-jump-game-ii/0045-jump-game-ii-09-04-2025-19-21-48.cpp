class Solution {
public://jump game jaisa
int solve(vector<int> &nums, int i, vector<int> &dp){
    if(i>=nums.size()-1)
        return 0;

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
    }
};