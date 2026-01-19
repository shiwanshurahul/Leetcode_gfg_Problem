class Solution {
public:
int solve(vector<int>& nums,int k){
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp;
        int ans = 0;

        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;   //remove calcn for i
                if(mp[nums[i]] ==0 )  
                    mp.erase(nums[i]);
                i++;      //slide the window
            }
            ans += (j-i+1);  //har bar
            j++;
        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //variable size sliding window -> sum/mp.size() >k
        ////2 bar ans nikalene ki socho and j-i+1 is o/p
        //type- 3 of sliding window -> 1 case likho
        
        //map rkhlo and size lete rho ==k
        int x = solve(nums,k);
        int y = solve(nums,k-1);
        return abs(x-y);
    }
};