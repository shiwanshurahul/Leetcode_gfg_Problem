class Solution {
public:
int ans = 0;
void solve(int i, vector<int>& nums, int n, int k, unordered_map<int,int> &mp){
    if(i>=n){
        ans++;
        return;
    }

    if(mp.find(nums[i]-k) == mp.end() && mp.find(nums[i]+k) == mp.end() ) {  
        mp[nums[i]]++;        //pick -> increase freq  -> not present in mp
        solve(i+1,nums,n,k,mp);  //explore
        mp[nums[i]]--; //backtrack
        if(mp[nums[i]] == 0)
            mp.erase(nums[i]);
    }
    solve(i+1,nums,n,k,mp);  //skip     
}
    int beautifulSubsets(vector<int>& nums, int k) {
        //all possible/combint/permutan/subset -> backtrackin
        //pick ,skip -> chk nums[i] + k, nums[i]-k in mp

        int n = nums.size();
        //seedha lis lagaoge toh duplicate aaega
        unordered_map<int,int> mp;
        solve(0,nums,n,k,mp);
        return ans - 1; //1 for empty subset
    }
};