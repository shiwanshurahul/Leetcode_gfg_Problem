class Solution {
public:
int solve(int i,int j, vector<vector<int>> &matrix,int n, int m, vector<vector<int>> & dp){
    if(i>= n || i<0 || j>= m || j<0)
        return 0;

    if(matrix[i][j] ==0)
        return 0;

    if(dp[i][j] !=-1)
        return dp[i][j];    

    int right = solve(i, j+1, matrix, n, m, dp);
    int down = solve(i+1,j, matrix, n, m, dp);
    int diagonal = solve(i+1, j+1, matrix, n, m, dp);

    return dp[i][j] = 1 + min({right, down, diagonal}); //har 1 val wale index ka ans bhej rha   
}

int top_down_tabulation(vector<vector<int>> &matrix, int n,int m){
    vector<vector<int>> dp(n+1, vector<int> (m+1,0));
    int cnt =0; // cnt sirf 1 ka chaiye
    //0th row
    for(int i=0;i<m;i++){
        dp[0][i] = matrix[0][i];  //0 toh o, 1 toh 1
        cnt+= dp[0][i];   //0 add 0 me 
    }

    //0th col
    for(int i=0;i<n;i++){
        dp[i][0] = matrix[i][0]; //0 toh 0, 1 toh 1
        cnt += dp[i][0]; 
    }

    if(dp[0][0] ==1)
        cnt--;  //2 bar add kr liya

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] == 1)
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            cnt += dp[i][j];    
        }
    }
    return cnt;
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
        //  }  //1+ .. bcz 1 toh hai hi ye of len 1*l
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1)  //har 1 pe find ans -> idhar v teeno recursive functi call kr skte
                    ans += solve(i,j,matrix,n,m,dp);
            }
        }
        return ans;

        // return top_down_tabulation(matrix,n,m); //dp[i][j] = har idx me store kitna submatrix hai jo i,j pe khatam hoga

    } // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
};