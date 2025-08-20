class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // int j=1;  //isko odd letters pe rakho
        // for(int i=0;i<nums.size();i++){
        //     if(i%2 ==0 && nums[i]%2 != 0 ){
        //         swap(nums[j],nums[i]);
        //         j++;
        //     }
        // }
        // return nums;
        int n =nums.size();
        vector<int> even;
        vector<int> odd;
        vector<int> ans;
        for(auto it: nums){
            if(it%2==0)
                even.push_back(it);
            else
                odd.push_back(it);    
        }
        for(int i=0;i<n;i++){
            if(i%2==0)
                ans.push_back(even[i/2]);
            else
                ans.push_back(odd[i/2]);   
        }
        return ans;
    }
};