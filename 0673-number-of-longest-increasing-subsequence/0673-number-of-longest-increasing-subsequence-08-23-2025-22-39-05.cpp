class Solution {
public:
int solve(vector<int> &nums, int i, int prev){
    if( i >= nums.size()){

        return 0;
    }
        
    int skip = 0;
    int take =0;

    if(prev ==-1 || nums[i] > nums[prev] ){
        take = 1 + solve(nums,i+1,i);
        skip = solve(nums,i+1,prev);   //dp hai na
    }
    else{
        skip = solve(nums, i+1,prev);
    }

    return max(skip, take);  //max len de rha lis ka
}
int tabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1); //cnt[i] = cnt of lis ending at i
    
    //dp[i] -> longest lis ending at idx i
    // if nums[i] > nums[j] tb dp[i] me store dp[j] pe no of lis +1

    int max_lis = 1;   //default
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]> nums[j]){  //lis ka cond
                if(dp[j] + 1 == dp[i]){   //already vis
                    cnt[i] += cnt[j];
                }
                else if(dp[j] + 1 > dp[i]){
                    dp[i] = dp[j]+1;   // or dp[i] = max(dp[i], dp[j]+1)
                    cnt[i] = cnt[j];    
                    max_lis = max(max_lis,dp[i]);
                }    
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i] == max_lis)
            ans += cnt[i];
    }
    return ans;
}
    int findNumberOfLIS(vector<int>& nums) {
    //  return solve(nums, 0, -1); 
    //tabulation ke sath cnt array lelo and fill
     return tabulation(nums);  
    }
};