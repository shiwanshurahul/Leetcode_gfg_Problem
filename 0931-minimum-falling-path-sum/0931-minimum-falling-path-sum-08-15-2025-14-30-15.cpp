class Solution {
public:
//express base case in i and j
//explore all possible solutions
//return min, max, sum ..

//row+1 har bar, but col-1, col, col +1
int solve(vector<vector<int>> &matrix, int i, int j, int n, int m, vector<vector<int>> &dp){
   
    if(j<0 || j> m-1 || i<0 || i> n-1 )
        return 1e9;

     if(i == n-1 )  //last row
        return matrix[i][j];   //add is indx ki value to your sum

    if(dp[i][j] !=-1)
        return dp[i][j];
    int min_sum = 1e9;
    for(int shift = -1;shift <=1;shift++){  
        if(i+1 < n)
        min_sum = min(min_sum,matrix[i][j] + solve(matrix, i+1, j+shift, n, m, dp));
    }   // 3 calls ki jagah 1 se
   
    return dp[i][j] = min_sum;
        
}
int tabulation(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1e9;
        
       vector<vector<int>>dp(n, vector<int>(m,1e9));
       //fill first row
    //    for(int i=0;i<n;i++){
    //         for(int j=0;j< m;j++){
    //             if(i ==0 ) //1st col 2 1 3
    //                 dp[i][j] = matrix[i][j];
    //         }
    //    }    better method:

    for(int i=0;i< n;i++){
        dp[0][i] = matrix[0][i];
    }


       //store min sum in curr:  curr + min(dp[i-1][j-1] , dp[i-1][j]m dp[i-1][j+1])
       for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j -1>=0 && j < m-1)
                dp[i][j] = min({dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]}) + matrix[i][j]; //cur val toh add hogi hi
            else if(j- 1 <0 )  
                dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
            else if( j-1 >= 0 )
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + matrix[i][j];    
        }
       }
       //last row me min val
       for(int i=n-1;i<n; i++){
        for(int j=0; j< m; j++){
            ans = min(ans, dp[i][j]);
        }
       }
       return ans;

}
    int minFallingPathSum(vector<vector<int>>& matrix) {

        return tabulation(matrix);
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     int ans = 1e9;
        
    //    vector<vector<int>>dp(n, vector<int>(m,-1));

    //     for(int col=0;col<m;col++){  //first row me sare idx se check
    //         ans = min(ans, solve(matrix, 0, col, n, m, dp));
    //     }
        //memoization se v tle
        //1937 similar
        // return ans;
    }
};