class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 0;
        int maxi = cnt;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])
                cnt++;
            else
                cnt=0;    

            maxi = max(maxi, cnt);    
        }
        return maxi+1;

    }
};