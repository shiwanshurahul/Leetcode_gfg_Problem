class Solution {
public:
int solve(int i,int j, vector<vector<int>> &matrix,int n, int m, vector<vector<int>> & dp){
    if(i>= n || i<0 || j>= m || j<0)
        return 0;

    if(matrix[i][j] ==0)
        return  0;

    if(dp[i][j] !=-1)
        return dp[i][j];    

    int right = solve(i, j+1, matrix, n,m, dp);
    int down = solve(i+1,j, matrix,n,m, dp);
    int diagonal = solve(i+1,j+1, matrix,n,m, dp);

    return dp[i][j] = 1+ min(right, min(down, diagonal));    
}
    int countSquares(vector<vector<int>>& matrix) {
        //i ke right(hor) me 1, down(ver) me 1,diagonal me 1 = teeno me hoga squ toh squ of 2 size bnega
        //  ____
        //  |i|_|       => square of 2 size
        //  |_|_|

        // i ke right me 1 squ in horiz, 1 squar in down, but 0 squa in diag = not a squ of 2 size = squ of only 1 size 
        //  if(matrix[i][j] == 1){   //har i==1 pe 3 recursive call hoenge
        //     int right = ..    here, 1
        //     int down = ..     here, 1
        //     int diag = ..     here, 0
        //     1+ min(right, down, diag);  ka squa bnega
        //  }
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<vector<int>> dp(n, vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1)  //har 1 pe find ans
                    ans += solve(i,j,matrix,n,m,dp);
            }
        }
        return ans;

    }
};