class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int cnt_0 =0;
        int ans =0;
        while(j<nums.size()){
            if(nums[j] == 0)
                cnt_0++;
            while(cnt_0 >1){
                if(nums[i]==0)
                    cnt_0--;
                i++;    
            }    

            ans = max(ans, j-i+1);  //har bar
            j++;
        }
        return ans-1; //tmne 1 0 include krke len nikala 
    }
};