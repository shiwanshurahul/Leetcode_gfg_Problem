class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //prefix sum lo
        //ek bar me 2k+1 elem dekhna hai
        //har elem ka i-k se i+k tak avg  = i+k lelo prefix_sum se and usme se - prefix_sum[i-k-1];
        if(k==0)
        return nums;
        int n =nums.size();
        vector<long long> prefix_sum(n);
        vector<int> ans(n,-1);  //suru and last ke k -1 rhenge 
        
        //sbka prefix sum store kro
        prefix_sum[0] = nums[0]; 
        for(int i=1;i<n;i++){
            prefix_sum[i] = nums[i] + prefix_sum[i-1];
        }
        
        for(int i=k;i<=n-k-1;i++){
            if(i-k >0)  //exists tb na ghataoge, i =4,5
                ans[i] = (prefix_sum[i+k] - prefix_sum[i-k-1]) / (2*k+1); 
            else  //i-k-1 ni exists i =3 pe
                ans[i] = prefix_sum[i+k] / (2*k+1);
           cout<<i<<ans[i]<<endl;     
        }
//         35
//         44
//         54
      
        return ans;
    }
};