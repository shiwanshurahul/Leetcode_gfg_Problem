class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int unique_cnt_even = 0;
        int unique_cnt_odd = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp.find(nums[j]) == mp.end() ){ //only unique
                    if(nums[j]%2 == 0)   //even
                        unique_cnt_even++;
                    else  //even
                        unique_cnt_odd++;  
                          
                    mp[nums[j]] = 1;     
                    if(unique_cnt_odd = unique_cnt_even)
                        ans = max(ans, j-i+1);  
                }
            }
        }
        return ans;
    }
};