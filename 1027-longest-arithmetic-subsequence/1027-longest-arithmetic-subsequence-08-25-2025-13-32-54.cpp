class Solution {
public:
int dp[1001][1003];
//express i and j for base case
//explore all possible cases
//return max, min, sum ..
int solve(vector<int> &nums, int i, int diff){  //i ke eft me jana
    
    if(i<0) //left me dhnudh rhe
        return 0;

    if(dp[i][diff+501] !=-1)
        return dp[i][diff+501];

    int ans =0;
    for(int k=i-1;k>=0;k--){
        if(nums[i]- nums[k] == diff)
            ans = max(ans, 1+solve(nums,k,diff)); // k ke left me jake same diff check 
    }

    return dp[i][diff+501] = ans;
}
    int longestArithSeqLength(vector<int>& nums) {
        //lis ka variation -> A.P
        //famous 
        //sare common diffe me check krlo
        if(nums.size() <=2)
            return nums.size();

        memset(dp,-1,sizeof(dp));    

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + solve(nums,i,diff));  //left me jake check common diff
            }
        }
        return ans;
    }
};