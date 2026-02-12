class Solution {
public:
int dp[10001];
int solve(int i,int n, vector<int>&jumps){
    if(i>=n)
        return 0; //add 0 to min step jo lge

    if(dp[i] !=-1)
        return dp[i];

    int ans = 1e9;
    for(int j=1;j<=jumps[i];j++){
        ans = min(ans, 1 + solve(i+j,n,jumps));
    }
    return dp[i] = ans;   
}
    int minTaps(int n, vector<int>& ranges) {
        //similar to jump gam 2
        vector<int> left(n+1,0);  // [0,0,1,2,4,5]
        vector<int> right(n+1,0); // [3,5,3,4,4,5]
        vector<int> jumps(n+1, 0);

        for(int i=0;i<n+1;i++){
            // left[i] = max(0,i-ranges[i]);
            // right[i] = max(n, min(n,i+ranges[i]));
            int left_idx = max(0,i-ranges[i]);
            jumps[left_idx] = max(jumps[left_idx] ,min(n, i+ ranges[i])); 
        }

        for(int i=0;i<n+1;i++){ 
            jumps[i] -= i; //converting the rightmost jump indx 
        }                   //to jump length from i
        
        memset(dp,-1,sizeof(dp));        
        int ans = solve(0,n,jumps);
        cout<<ans;
        return ans == 1e9 ? -1 : ans ;
    }  //sbka i se initallly call jaega fir sbka j chlega and min aega
};