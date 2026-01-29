class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //min len  = min size window nikalo
        //variable size window -> 2 bar ans cal krne ki kosis
        int i=0,j=0;
        int ans=1e9;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(sum<target){
                j++;
            }
            else if(sum==target){
                ans = min(ans,j-i+1);
                j++;
            }
            else if(sum>=target){
                while(sum>=target){
                    ans = min(ans,j-i+1);    //ans store
                    sum -= nums[i];          // remove caln for i
                    i++;                     // slide window  
                    if(sum==target)
                        ans = min(ans,j-i+1);
                }
                j++;
            }
        }
        if(ans==1e9)
            return 0;
            return ans;
    }
};