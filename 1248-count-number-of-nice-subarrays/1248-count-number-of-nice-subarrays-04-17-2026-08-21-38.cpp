class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // no of subarrays = ans+= 
        // [2,1,2,1], k=1 -> o/p = 6
        // [2,1,2], k=1 -> o/p = 4
        int i=0,j=0;
        int odd_cnt = 0;  //cnt of odd
        // int prev_cnt = 0;
        int ans = 0;
        // while(j<nums.size()){
        //     if(nums[j] %2 !=0){  //odd no
        //         odd_cnt++;
        //         prev_cnt = 0;
        //     }
        //     while(odd_cnt == k){
        //         prev_cnt++;    
        //         if(nums[i] %2 ==1)  //remove caln for i
        //             odd_cnt--;
        //         i++;                //slide the window
        //     } 
        //     ans += prev_cnt;   //har br
        //     j++;  
        // }

        //m2:
         //subara with sum k
        unordered_map<int,int> mp;
        mp[0] = 1;  //odd_cnt = 0 dekh
        while(j<nums.size()){
            odd_cnt += (nums[j]%2 == 1 ? 1 : 0);
            if(mp.find(odd_cnt -k) != mp.end())
                ans += mp[odd_cnt-k];

            mp[odd_cnt]++;
            j++;
        }
        return ans;
    }
};