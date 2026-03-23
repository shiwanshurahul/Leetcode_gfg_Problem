class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //svi no ka each digit me set bits(1) check kro

        // for every bit position:
            //Count how many numbers have 0
            //Count how many numbers have 1

        //Since most numbers appear 3 times, their bits contribute in 
        //multiples of 3.
        // If at any bit position the count of 1s % 3 == 1, it means that 
        //bit belongs to the unique number. 

        int ans = 0;
        for(int i=0;i<32;i++){  //check each bit position from 0 to 31.
            int cnt_1 =0;
            for(auto it: nums){  // sare no ka ith bit check kr rh
                if((it & (1<<i)) !=0)  //check if ith bit is set or wat
                    cnt_1++;
            }
            if(cnt_1 %3 ==1)    //single no
                ans = ans | (1<<i);  //us postion pe set bit daldo    
        }
        return ans;
    }
};