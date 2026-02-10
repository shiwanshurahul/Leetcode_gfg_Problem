class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        //constrait km hai
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            unordered_set<int> st_odd, st_even; //is pure i to j tk
            for(int j=i;j<n;j++){
                if(nums[j]%2 == 0)   //even
                    st_even.insert(nums[j]);
                else  //odd
                    st_odd.insert(nums[j]);

                if(st_even.size() == st_odd.size())
                    ans = max(ans, j-i+1);  
            }
        }
        return ans;
    }
};