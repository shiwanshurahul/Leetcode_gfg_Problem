class Solution {
public:
int dp[1000001];
typedef long long ll;
const int M = 1e9 +7;
int solve(int idx, string& s, int n, int k){
    if(idx>=n)
        return 1;

    if(s[idx]=='0')
        return 0;

    if(dp[idx] !=-1)
        return dp[idx];

    ll ans = 0; 
    ll num = 0;

    for(int i=idx;i<n;i++){
        num = stoi(s.substr(idx,i-idx+1));
        if(num>k)
            break;// No need to check longer segments  
        ans = ( (ans%M) + (solve(i+1,s,n,k))%M )%M;    
    }
    return dp[idx] = (int)ans;    
}
    int numberOfArrays(string s, int k) {
        //har point pe try to split
        if(s[0]=='0')
            return 0;
        memset(dp,-1,sizeof(dp));    
        return solve(0,s,s.length(),k);
    }
};