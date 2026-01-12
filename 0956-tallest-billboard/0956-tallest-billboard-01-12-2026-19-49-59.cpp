class Solution {
public:
// int dp[21][2001][2001];
int dp[21][10001];
int solve(int i,int l1,int l2,vector<int>& rods, int n){
    if(i>=n){  //tle
        if(l1==l2)
            return l1; //or l2
        return 0;   
    }

    // if(dp[i][l1][l2] !=-1)
    //     return dp[i][l1][l2];

    int no_rod = solve(i+1,l1,l2,rods,n);
    int add_l1 = solve(i+1,l1+rods[i],l2,rods,n);
    int add_l2 = solve(i+1,l1,l2+rods[i],rods,n);

    return max({no_rod, add_l1, add_l2}); 

}

int solve1(int i, int diff, vector<int>& rods, int n){
    if(i>=n){  //tle
        if(diff == 0)
            return 0; 
        return -1e9;   
    }

    if(dp[i][diff+5000] !=-1)
        return dp[i][diff+5000];

    int no_rod = solve1(i+1,diff,rods,n); //no change in diff
    int add_l1 = rods[i] + solve1(i+1, diff+rods[i], rods, n);
    int add_l2 = solve1(i+1, diff-rods[i] ,rods, n);

    return dp[i][diff+5000] = max({no_rod, add_l1, add_l2}); 

}
    int tallestBillboard(vector<int>& rods) {
        //do l lelo and dono me add krke try kro
        //both same len ka hona chahiye
        memset(dp,-1,sizeof(dp));
        // return solve(0,0,0,rods,rods.size()); //i,l1,l2

        //3-d dp hai = memory level exceeded = 2-d dp me diff store -> l1=l2 store krna hai
        return solve1(0,0,rods,rods.size());
    }
};