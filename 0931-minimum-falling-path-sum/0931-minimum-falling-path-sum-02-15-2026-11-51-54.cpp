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

    // int down_left = matrix[i][j] + solve(matrix, i+1, j-1, n, m, dp);
    // int down = matrix[i][j] + solve(matrix, i+1, j, n, m, dp); 
    // int down_right = matrix[i][j] + solve(matrix, i+1, j+1, n, m, dp);
    //or:
    
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
        //bootom -up ko opposite dirn me likhte as recusio
        int n = matrix.size();
        int m = matrix[0].size();
        
       vector<vector<int>>dp(n, vector<int>(n,1e9));

        for(int i=0;i<n;i++){    //first row me val matrix se populate kro
            dp[0][i] = matrix[0][i];
        }
       //store min sum in curr: curr + min(dp[i-1][j-1] , dp[i-1][j], dp[i-1][j+1])
        for(int i=1;i<n;i++){  //second row se fill
            for(int j=0;j<n;j++){   //i-1 toh hai hi and for col: j, j-1,j+1
                int a = 1e9;
                int b = 1e9;
                if(j-1 >=0)
                    a = dp[i-1][j-1];
                if(j+1 <n)
                    b = dp[i-1][j+1];    
            
                dp[i][j] = min({dp[i-1][j], a, b}) + matrix[i][j]; 
            }  //cur val toh add hogi hi
        }
        //get min from last row
        int ans = 1e9;
        for(int i=0;i<m;i++){
                ans = min(ans, dp[n-1][i]);
        }
       return ans;

}
    int minFallingPathSum(vector<vector<int>>& matrix) {

        // int n = matrix.size();
        // int m = matrix[0].size();
        // int ans = 1e9;
        
        //  vector<vector<int>>dp(n, vector<int>(m,-1));

        // for(int col=0;col<m;col++){  //first row me sare idx se check
        // ans = min(ans, solve(matrix, 0, col, n, m, dp));
        // }
        //memoization se v tle
        //1937 similar
        // return ans;
        return tabulation(matrix);
       
    }
};