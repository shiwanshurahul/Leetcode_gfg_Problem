class Solution {
public:
int solve(vector<int> &arr, int difference, int i, int prev, vector<vector<int>> &dp){
    if(i>= arr.size())
        return 0;

    if(prev != -1 && dp[i][prev+1] !=-1)
        return dp[i][prev+1];

    int take = 0;
    int skip = 0;

    if( prev == -1 ||  arr[i] - arr[prev] == difference ){
        take = 1 + solve(arr,difference, i+1,i, dp);
        skip = solve(arr, difference, i+1, prev, dp);   //dp
    }
    else {
        skip = solve(arr, difference, i+1, prev, dp);
    }

    return dp[i][prev+1] = max(take, skip);
}
int tabulation(vector<int> &arr, int difference){

    int n =arr.size();
    vector<int> dp(arr.size(),1);
    int max_lis = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]- arr[j] == difference){
                dp[i] = max(dp[i], dp[j] +1);   //lis
                max_lis = max(max_lis, dp[i]);
            }
        }
    }
    return max_lis;

}
int solution(vector<int> &arr, int difference){
    
    int maxi= 0;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        if(mp.count(arr[i] - difference))
            mp[arr[i]] = mp[arr[i]-difference] +1;  
        else    
            mp[arr[i]] = 1;
        maxi = max(maxi, mp[arr[i]]);        
    }
    return maxi;
}
    int longestSubsequence(vector<int>& arr, int difference) {
        //lis pattern
        // vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        // return solve(arr,difference,0,-1, dp); 
        //memoizaton me v tle

        // return tabulation(arr, difference);  //isse v tle
        return solution(arr, difference);
    }
};