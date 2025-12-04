class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <=1)
        return 0;
        int i=0,j=0;
        int prod=1;
        int ans=0;
        while(j< nums.size()){
            prod = nums[j] *prod;
            while( prod >= k){
               prod = prod/nums[i];
               i++;
            }
            ans = ans+ j-i+1;  //no of subarray ending at j
            j++;
        }
        return ans;
    }
};