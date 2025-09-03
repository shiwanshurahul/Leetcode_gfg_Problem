class Solution {
public:
int solve(vector<int> &nums, int target, int i, vector<vector<int>> &dp){
    if(target==0)
        return 0; //1 way mila

    if(i>= nums.size() || target <0)
        return -1e9; 

    if(dp[i][target] != -1)
        return dp[i][target];

    int include = 1 + solve(nums,target-nums[i],i+1, dp);
    int exclude = solve(nums,target,i+1, dp);

    return dp[i][target] = max(include, exclude);     //ye toh total no of subsequences/comninations dega tmko longest subsequence ka len chahiye  
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        //sliding window for substring,subarray -> variable size = 2 bar ans dhundhne ki kosis
        //idhar substring
        // int i=0,j=0;
        // int max_len = -1;
        // int sum=0;

        // while(j<nums.size()){
        //     sum += nums[j];
        //     if(sum<target){
        //         j++;
        //     }
        //     else if(sum == target){
        //         max_len = max(max_len,j-i+1);
        //         j++;
        //     }
        //     else if(sum >= target){
        //            while(sum>= target){
        //                sum -= nums[i];
        //                i++;
        //                if(sum==target)
        //                   max_len = max(max_len, j-i+1);
        //            }
                    
        //             j++;
        //     }
        // }
        // return max_len;

        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        int ans = solve(nums, target, 0, dp);
        if(ans <=0)
            return -1;
        return ans;    
           
        } 
};