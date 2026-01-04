class Solution {
public:
typedef long long ll;
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e9;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int s = i+1, e = n-1;
            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if ( abs(sum - target) < abs(ans - target) )
                    ans = sum;

                if(sum == target)
                    return sum;    
                else if( sum> target)
                    e--;
                else if(sum < target)
                    s++;
            }    
        }
        return ans;
    }
};