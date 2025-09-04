class Solution {
public:
    int jump(vector<int>& nums) {
       int curreach =0;
       int maxreach =0,jumps=0;
       for(int i=0;i<nums.size()-1;i++){
           if(nums[i]+i>maxreach)
           maxreach= nums[i]+i;
           if(i==curreach){
               jumps++;
               curreach =maxreach;
           }
       }
       return jumps;

    }
};