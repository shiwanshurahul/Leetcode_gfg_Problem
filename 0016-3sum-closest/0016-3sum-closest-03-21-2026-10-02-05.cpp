class Solution {
public:
typedef long long ll;
    int threeSumClosest(vector<int>& nums, int target) {
        //brute force -> o(n3)
        //here, logn+o(n^2)
        int n = nums.size();
        int ans = 1e9;
        sort(nums.begin(),nums.end());  //[-4,-1,1,2]

        for(int i=0;i<n;i++){
            int s = i+1, e = n-1;  //i=-4,s=-1,e=2 ; s=1 ; e=1 = out of while
            while(s<e){            //=i++ = i=-1,s=1,e=2 
                int sum = nums[i] + nums[s] + nums[e];  //-3 ; -1 ;2
                if(abs(sum-target) < abs(ans-target) )
                    ans = sum;  //closest sum  -3; -1 ;  2

                if(sum == target)
                    return sum;  //= target    
                else if( sum> target)
                    e--;
                else if(sum < target)
                    s++;
            }    
        }
        return ans;
    }
};