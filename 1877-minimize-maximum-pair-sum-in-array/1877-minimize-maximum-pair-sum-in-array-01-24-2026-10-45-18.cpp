class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //sort ->2,3,3,5
        //io=, e= n-1 se pair kro
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = -1e9;
        int s=0,e=n-1;
        while(s<e){
            maxi = max(maxi,nums[s]+nums[e]);
            s++;
            e--;
        }
        return maxi;
    }
};