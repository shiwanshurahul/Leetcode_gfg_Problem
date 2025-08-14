class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j =0;
        int n = nums.size();
         if(n <=1)
             return double(nums[0]);
       
        double maxi_avg = -100000;
        double sum=0;
        while(j< n){
            sum+= nums[j];
            if(j-i+1 <k){
                j++;
                continue;
            }
            else{
                maxi_avg = max((double) sum/k, maxi_avg);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return maxi_avg;
    }
};