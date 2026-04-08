class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)   //-ve
                swap(maxi,mini); //maxi=3, mini=6
            maxi = max(nums[i],maxi*nums[i]);  //6,-2,-4
            mini = min(nums[i],mini*nums[i]);  //3,-12,-48
            ans = max(maxi,ans);
        }
        return ans;
    }
};