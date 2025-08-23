class Solution {
public:
//subsequence =skip or take at each step
//inhi dono me stored rhega ans
int n; 
int dp[2501][2501];
int solve(vector<int>& nums,int i,int p){
    if(i>=n)
    return 0;

    if(p!=-1 && dp[i][p] !=-1)
    return dp[i][p];
 int take =0; //if ke andar define toh if ke bahar can't access
    if(p==-1 || nums[i]>nums[p])
     take =1 +solve(nums,i+1,i);// p==i;
    
   int skip = solve(nums,i+1,p);
   
    if(p!=-1)
    return dp[i][p] = max(take,skip);
    else
    return max(take,skip);
}
    int lengthOfLIS(vector<int>& nums) {
        n= nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
        //two parametres are changing = 2-d dp 
    }
};