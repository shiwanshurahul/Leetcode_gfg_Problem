class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum=0, maxi = -1e9;
        for(int i=0;i<nums.size();i++){ // ->  No
            sum+= nums[i];
            maxi = max(maxi,sum);
            if(sum<0)
                sum=0;
        }
        return maxi== -1e9 ? nums[0] : maxi; 

        //m-2:
        // for(int i=1;i<nums.size();i++){
        //     sum = max(nums[i], sum+nums[i]); //sum with cur elem
        //     maxi = max(maxi,sum);
        // }
        // return maxi; 
    }
};