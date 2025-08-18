class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans =0;
        int i = 0, j=0;
        long sum=0;
       while(j<n){
            long target = nums[j];
            sum+= nums[j];
            while((j-i+1)* target - sum > k) {  //window shrink
                sum -= nums[i];
                i++;
            }

            ans = max(ans, j-i+1);  //har bar
            j++;
        }
        return ans;
    }
};