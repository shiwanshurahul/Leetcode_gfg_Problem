class Solution {
public:
int dp[601][101][101];
int solve(vector<string>& strs, int m, int n, int i){
    if(i>= strs.size() || m<0 || n<0 )
        return 0;  
    
    if(dp[i][m][n] !=-1)
        return dp[i][m][n];

    int cnt_0 = 0;  //keep track -> har recursive call ka apna
    int cnt_1 = 0;        //chaho toh m-- v kr skte us case me m_=m rakh lo for skip

    for(int j=0;j<strs[i].length();j++){
        if(strs[i][j] == '0')
           cnt_0++;
        else
            cnt_1++;    
    }

    int pick = 0;
    int skip = 0;

    if( m-cnt_0 >=0 && n-cnt_1 >=0 ){    //->direct pick,skip likh skte
        pick = 1 + solve(strs, m-cnt_0, n-cnt_1, i+1);
        skip = solve(strs, m, n, i+1);   //choice of dp
    }
    else {  //skip hi kr skte
          skip =  solve(strs, m, n, i+1);
    }

     return dp[i][m][n] = max(pick,skip);   

}
    int findMaxForm(vector<string>& strs, int m, int n) {
        //m and n se jyada na jaye pure subset me = choice = dp

        memset(dp,-1,sizeof(dp));

        // vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>> (m+1, vector<int> (n+1,-1)));
        return solve(strs,m,n,0);
    }
};