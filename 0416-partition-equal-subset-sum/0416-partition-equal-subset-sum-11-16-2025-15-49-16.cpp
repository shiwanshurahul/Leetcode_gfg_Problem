class Solution {
public:
int dp[201][10001];
bool solve(vector<int>& nums, int sum,int idx, int n){
    if(idx >=n || sum <0)
        return 0;
    if(sum ==0)
        return 1;

    if(dp[idx][sum] !=-1)
        return dp[idx][sum];

    int pick = 0;
    int skip = 0;
    if(nums[idx] <=sum){
        pick = solve(nums,sum-nums[idx], idx+1,n);
        skip = solve(nums,sum,idx+1,n);  //choice of dp
    }
    else{  //can;t take
         skip = solve(nums,sum,idx+1,n);
    }
    return dp[idx][sum] = pick || skip;

}
    bool canPartition(vector<int>& nums) {
        //if total_sum%2 is an integer toh maybe solution exists
        //tab subset sum lagao with total_sum/2 -> is there any subset exists with sum/2 in this array
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum%2 !=0)
            return false;
         
        memset(dp,-1,sizeof(dp));
        return solve(nums,sum/2,0,nums.size());
    }
};