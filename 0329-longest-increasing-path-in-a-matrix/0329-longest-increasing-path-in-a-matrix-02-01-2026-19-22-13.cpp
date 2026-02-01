class Solution {
public:
int n = 0;
int m = 0;
int dp[201][201];
vector<vector<int>> dirn = {{-1,0},{1,0},{0,1},{0,-1}};
bool is_valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return 0;
    return 1;    
}
int solve(int i,int j, vector<vector<int>>& matrix){
    if(! is_valid(i,j))
        return 0;
        
    if(dp[i][j] !=-1)
        return dp[i][j];

    int res = 1;  //single toh hai

    for(auto it: dirn){
        int i_ = i + it[0];
        int j_ = j + it[1];
        if(is_valid(i_,j_) && matrix[i_][j_] < matrix[i][j] ){
            res = max(res, 1 + solve(i_,j_,matrix));
        }
    }
    return dp[i][j] = res;

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        //same as 2328, count of squar submatrice
        //dp hai
        
        n = matrix.size();
        m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;
    }
};