class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int n =nums.size();
        // vector<int> even;
        // vector<int> odd;
        // vector<int> ans;
        // for(auto it: nums){
        //     if(it%2==0)
        //         even.push_back(it);
        //     else
        //         odd.push_back(it);    
        // }
        // for(int i=0;i<n;i++){
        //     if(i%2==0)
        //         ans.push_back(even[i/2]);
        //     else
        //         ans.push_back(odd[i/2]);   
        // }
        // return ans;

         int even=0,odd=1;
         while(even<n && odd<n){
            if(even %2 == 0 && nums[even]%2 ==0)
                even+= 2;
            
            else if(odd%2 !=0 && nums[odd]%2 !=0)
                odd +=2; 
            
            else
                swap(nums[even], nums[odd]);  //dono me mismatch hoga
           
            }
         return nums;


    }
};