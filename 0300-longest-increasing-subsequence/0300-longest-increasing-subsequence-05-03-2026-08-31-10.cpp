class Solution {
public:
int solve(vector<int> &nums, int i, int prev, vector<vector<int>> &dp){
    if(i >= nums.size())
        return 0;   //0 add krke return as already cnt le rhe

    if(prev !=-1 && dp[i][prev+1] !=-1 )
        return dp[i][prev+1];

    int take = 0;
    int skip = 0;

    if(prev == -1 || nums[i] > nums[prev]){
        take = 1 + solve(nums,i+1,i, dp);   //1 len added
        skip = solve(nums,i+1,prev, dp);   //choice of dp
    }
    else{   //nums[prev] is > nums[i] = skip hi kr skte
        skip = solve(nums,i+1,prev, dp); 
    }

    return dp[i][prev+1] = max(take,skip);    
}
int tabulation(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(nums.size(), 1);  //by dafault 1 len ka khud
    // dp[i] -> lis ending at idx i
    //logicl
    //if i & j are in lis then i j se puchega tujh pe khatam hone wala lis
    // ka cnt kitna hai
    // previously calc answers to calc the ans for the next position

    int max_lis = 1;
    for(int i=0;i<n;i++){  // har i ke liye us tak j chlega
        for(int j=0;j<i;j++){  //usse pehle tak na
            if(nums[i]> nums[j])  //tbhi lis bnega na
                dp[i] = max(dp[i], dp[j]+1); //(abtak ka,dp[j] me stored + 
                                                           // khud ko includ)
            max_lis = max(max_lis, dp[i]);  //keep track
        }
    }
    return max_lis;  //tc-> o(n^2)
}
    int lengthOfLIS(vector<int>& nums) {
        //famous typ
        //subsequence wale me can think of lis or dp

        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        // return solve(nums,0,-1, dp);  //prev at -1 idx
        return tabulation(nums);
    }
};