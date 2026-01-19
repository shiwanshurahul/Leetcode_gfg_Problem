class Solution {
public:
typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //fixed size window = ek bar j-i+1 == k toh maintain rkho
        ll i=0,j=0;
        ll ans = 0;
        ll n = nums.size();
        ll sum = 0;
        unordered_map<ll,ll> mp;
        while(j<n){
            mp[nums[j]]++;
            sum+= nums[j];
            if(j-i+1 <k){
                j++;
            }
            else if(j-i+1 == k){  //maintain rkho size
                if(mp.size()== k){  //sb unqiue hai mp me
                    ans = max(ans,sum);
                }
                mp[nums[i]]--;    //remove calcn for i
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                sum-= nums[i];    
                i++;              //slide the window   
                j++;     
            }
        }
        return ans;
    }
};