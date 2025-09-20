class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=nums[0], maxi = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     sum+= nums[i];
        //     maxi = max(maxi,sum);
        //     if(sum<0)
        //         sum=0;
        // }

        //m-2:
        for(int i=1;i<nums.size();i++){
            sum = max(nums[i], sum+nums[i]); //sum with curr elem
            maxi = max(maxi,sum);
        }
        return maxi; 
    }
};