class Solution {
public://third type of slidin window -> j se i ko legal rkho warna slide
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int i=0,j=0;
        int maxi =-10000;
        //illegl ka case banao jb mp[ele] >k then remove from i
        while(j< nums.size()){
            mp[nums[j]]++;
            while(mp[nums[j]] > k){
                mp[nums[i]]--;  //remove calc for i and slide
                i++;
            }
               //mp me sbka cnt <=k hai
            maxi = max(maxi, j-i+1);  //har bar
            j++;        
        }
        return maxi;
    }
};