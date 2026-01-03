class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt_0=0,ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0)
            cnt_0++;

            while(cnt_0>k){
          if(nums[i]==0)
             cnt_0--;
             i++; //j=5,i=3
            }
            ans =max(ans,j-i+1);// 3,4,5
            j++;
        }
        return ans;
    }
};