class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            //  ans[i] =multiply all on left * multiply all on right
        /*    vector<int> left,right;
        left[0] =1;
            left[1] = nums[0];
            left[2] =nums[0]*nums[1];
            left[3] =nums[0]*nums[1]*nums[2];
    right[n-1] =1;
            right[n-2] =nums[n-1];
            right[n-3] =nums[n-2]*nums[n-1];
            right[n-4] =nums[n-3]*nums[n-2]*nums[n-1];
    
            ans[i] =left[i]*right[i];
    */
        int n = nums.size();
        vector<int> left(n),right(n),ans(n);
        left[0] =1;
        right[n-1] =1;
        for(int i=1;i<n;i++){
            left[i] =left[i-1]*nums[i-1];//1 1 2 6 
        }
        for(int i=n-2;i>=0;i--){
            right[i] =right[i+1]*nums[i+1];  //4 12 24 = 24 12 4 1
        }

        for(int i=0;i<n;i++){
            ans[i] =left[i]*right[i];
        }
        return ans;


 

    
    
       /* vector<int> ans;
        int p=1;
        int n =nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) p= p*nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            ans.push_back(p/nums[i]);
            else
            ans.push_back(0);
        }
        return ans;*/
    }
};