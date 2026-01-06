class Solution {
public:
int solve(int idx, vector<int>& jobDifficulty, int d, int n, vector<vector<int>> &dp){
    if(d==1){  //sare kam aj krne pdenge = max nikal lo
        int maxi = -1;
        for(int i=idx;i<n;i++){
            maxi = max(maxi,jobDifficulty[i]);
        }
        return maxi; //return and add this 
    }

    int maxD = -1;
    int ans = 1e9;

    if(dp[idx][d] !=-1)
        return dp[idx][d];

    for(int i=idx;i<=n-d;i++){
        maxD = max(maxD, jobDifficulty[i]);
        ans = min(ans,maxD + solve(i+1,jobDifficulty,d-1,n,dp));
    }
    return dp[idx][d] = ans;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
    
        if(d>jobDifficulty.size())
            return -1;
        vector<vector<int>> dp(jobDifficulty.size()+1,vector<int>(d+1,-1));
        int k = solve(0,jobDifficulty,d,jobDifficulty.size(),dp);
        return  k==1e9 ? -1 : k;
    }
};