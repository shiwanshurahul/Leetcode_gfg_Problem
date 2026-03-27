class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() ==0)
            return 0;
        sort(nums.begin(),nums.end());  //1,2,3,4,100,200
        int i=1, n = nums.size();
        int ans=0, cnt=0;

        while(i<n){
            if(nums[i] == nums[i-1]){
                i++;
                continue;   //skip duplicates
            }
            else if(nums[i]- nums[i-1] ==1 ){
                cnt++;
                ans = max(ans,cnt);
            }
            else{
                cnt = 0;
            }
            i++;
        }
        return ans+1;
    }
};

