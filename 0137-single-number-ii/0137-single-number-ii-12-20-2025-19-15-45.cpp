class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //svi no ka each digit me set bits(1) check kro
        int ans = 0;
        for(int i=0;i<32;i++){
            int cnt_1 =0;
            for(auto it: nums){  //sare no ka ith bit check krliya
                if((it & (1<<i)) !=0)  //check if ith bit is set or wat
                    cnt_1++; 
            }
            if(cnt_1 %3 ==1)
                ans = ans | (1<<i);  //us postion pe set bit daldo  
        }
        return ans;
    }
};