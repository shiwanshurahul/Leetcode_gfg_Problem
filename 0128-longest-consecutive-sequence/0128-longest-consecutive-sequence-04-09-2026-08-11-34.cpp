class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // // [100,4,200,1,3,2] -> 4
        // // [100,4,200,1,1,3,2]  -> 4
        // //duplicate hai and consecutiv mil rha toh don't brk 

        if(nums.size() ==0)
            return 0;
        sort(nums.begin(),nums.end());  //1,2,3,4,100,200
        int i=1, n = nums.size();
        int ans=0, cnt=0;

        while(i<n){    
            if(nums[i] == nums[i-1]){
                i++;
                continue;   //skip duplicates -> cnt =0 mt kro
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

        //m2:
        // if(nums.size() ==0)
        //     return 0;
        // unordered_set st(nums.begin(),nums.end());
        // int i=0;
        // int cnt=0, ans=0;
        // while(i< nums.size()){
        //     while(st.find(nums[i]) !=st.end() ){    //st me hai
        //         cnt++;
        //         ans = max(cnt, ans);
        //         nums[i]++;  //nums[i] me val add i.e 1,2,3,4,5,6
        //     }
        //     cnt= 0;
        //     i++;
        // }
        // return ans;
    }
};

