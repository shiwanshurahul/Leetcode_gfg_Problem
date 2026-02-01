class Solution {
public:
int n = 0;
int m = 0;
int M = 1e9 + 7;
int dp[1001][1001];
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;   //else  
}
int dfs(int i,int j, vector<vector<int>>&grid){
    if(! is_valid(i,j))
        return 0;

    int res = 1; //single elem toh hai hi
    if(dp[i][j] != -1)
        return dp[i][j];

    for(auto it: dirn){
        int i_ = i + it[0];
        int j_ = j + it[1];
        if(is_valid(i_,j_) && grid[i_][j_] < grid[i][j]){  //increasing
            res = (res%M + dfs(i_,j_,grid)%M)%M;
        }
    }
    return dp[i][j] = res%M;
}
    int countPaths(vector<vector<int>>& grid) {
        //strictly increasing

        n = grid.size();
        m = grid[0].size();
        //dfs likhoge kaise i.e pichle state ko maintain kaise kroge = dp 
        //no of strictly increasin paths ending at i,j -> func
        // -> 1<3<4


        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans%M + dfs(i,j,grid))%M;
            }
        }
        return ans;
    }
};