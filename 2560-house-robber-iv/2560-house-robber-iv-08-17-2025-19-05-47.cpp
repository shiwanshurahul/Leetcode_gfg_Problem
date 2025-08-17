#include <climits>
class Solution {
public:
//express base case in i,j
//explore all possible cases isme v max,min le skte
//return max, min, sum..
//nice type -> typical se thora alag
int solve(vector<int> &nums, int i, int k, vector<vector<int>> &dp){
    if(k == 0)  // 0 wala pehle calc ho chuka hai since k-1 kiye the = 1, 0 pe ja chuke already, and not k--
         return 0;

    if(i>= nums.size())
        return 1e9;     
 
    if(dp[i][k] != -1)
        return dp[i][k];

    int rob = max(nums[i], solve(nums, i+2, k-1, dp));   //k-- pe error, k-1 hi krna pdega
    int skip = solve(nums, i+1, k, dp);    

    return dp[i][k] = min(rob, skip);
}

bool is_possible(vector<int> &nums, int mid, int k){
    int house =0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<= mid){
            house++;
            i++; //skip adjacent house
        }
    }
    return house >=k;  //atleast k house rob kiya
}
    int minCapability(vector<int>& nums, int k) {
        //total k house are to be robbed 
        int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(k+1, -1)); //is pe tle
        // return solve(nums, 0, k, dp);

        //minimize the max or maximise the min -> binary search
        //mid jo aa rha wo capability hai
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());

        int ans =e;
        cout<<e;
        
        while(s<=e){
            int mid = (s+e)/2;
            if(is_possible(nums, mid, k)){
                ans = mid;
                e = mid-1; //aur left me jao
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};