class Solution {
public:
int n;
int dp[50001];
static bool cmp(vector<int>&a, vector<int>&b){
    return a[0] <= b[0];
}
int next_idx_to_pick(vector<vector<int>>& arr, int i, int endT){
    //l.s laga skte but sorted hai toh b.s 
    int s = i+1;
    int e = n-1;
    int ans = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid][0]>= endT){  //tbhi pick kr skte as next
            ans = mid;  //store and go as left
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int solve(int i, vector<vector<int>>&arr){
    if(i>=n)
        return 0; //add 0 profit and return
    if(dp[i] !=-1)
        return dp[i];
    int next_idx = next_idx_to_pick(arr, i, arr[i][1]);
    int pick = arr[i][2] + solve(next_idx,arr);
    int skip = solve(i+1,arr);

    return dp[i] = max(pick,skip);    
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        //sort krlo w.r.t st fir e.t and profit v = ek me hi rkhlo
        //[[1,3,50], [2,4,10], [3,5,40], [3,6,70]]
        //endTime_curr <= startTime_next tohi pick kr skte wo
        //pick and skip -> jidhar se max aay
        n = startTime.size(); 
        vector<vector<int>> arr(n, vector<int>(3,0)); //{s,e,p}
        for(int i=0;i<n;i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        sort(arr.begin(),arr.end(),cmp); //w.r.t sT
        memset(dp,-1,sizeof(dp));
        return solve(0,arr);
    }
};