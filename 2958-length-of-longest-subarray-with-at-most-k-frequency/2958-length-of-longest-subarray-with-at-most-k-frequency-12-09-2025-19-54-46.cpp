class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int maxi =-10000;
        //case banao jb mp[ele] >k then remove from i
        while(j< nums.size()){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;
                i++;
            }
               //mp me sbka count <=k hai
                maxi = max(maxi, j-i+1);
                j++;
            
        }
        return maxi;
    }
};