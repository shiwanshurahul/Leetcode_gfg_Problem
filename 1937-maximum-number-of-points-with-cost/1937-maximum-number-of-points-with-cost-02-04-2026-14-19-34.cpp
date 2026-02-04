class Solution {
public:
int n = 0;
int m = 0;
typedef long long ll;
long long tabulation(vector<vector<int>> &points){
    vector<vector<ll>> dp(n,vector<ll>(m,-1));

    for(int i=0;i<m;i++){  //0th row me same val as points
        dp[0][i] = points[0][i];
    }
    
    //fill rest of the table
    for(int row=1;row<n;row++){   //1st row se fill
        for(int col=0;col<m;col++){ 
            for(int k=0; k<m;k++){  //itertin on prev row
                dp[row][col] = max(dp[row][col], dp[row-1][k] -abs(col-k)
                                                 + points[row][col]);
            }
        }
    }

    //last row me max is ans
    ll ans = -1e9;
    for(int i=0;i<m;i++){
        if(dp[n-1][i] > ans)  //max ll pe ni chlt
            ans = dp[n-1][i];
    }
    return ans;  //tle -> n^3 -> o(n*m*m)
}

ll tabulation1(vector<vector<int>> &points){
    
    vector<vector<ll>> dp(n,vector<ll>(m,-1));

    for(int i=0;i<m;i++){  //0th row me same val as points
        dp[0][i] = points[0][i];
    }
    
    for(int i=1;i<n;i++){  //fill from 1st row
        vector<ll> left_dp(m, -1);  //for each row
        vector<ll> right_dp(m, -1);

        left_dp[0] = dp[i-1][0];
        for(int k=1;k<m;k++){
            left_dp[k] = max(left_dp[k-1], dp[i-1][k] + k);
        }
        
        right_dp[m-1] = dp[i-1][m-1] - m + 1;
        for(int k=m-2;k>=0;k--){
            right_dp[k] = max(right_dp[k+1], dp[i-1][k] - k);
        }
        
        for(int j=0;j<m;j++){
            dp[i][j] = max(left_dp[j]-j, right_dp[j]+j) + points[i][j];
        }
    }
    
    //find max in last row
    ll ans = -1;
    for(int i=0;i<m;i++){
        if(dp[n-1][i] > ans)
            ans = dp[n-1][i];
    }
    return ans;
}
    long long maxPoints(vector<vector<int>>& points) {
        //similar to min path falling sm
        //max sum path find
        
        // recursiv call for each i from i=0 to i=m-1 -> tle 
        // e.g. i+1,j-2, i+1,j-1, i+1,j  i+1,j+1, i+1,j+2, .. 
        n = points.size();
        m = points[0].size();
        // return tabulation(points); 
        return tabulation1(points);
    }
    //02 11
};