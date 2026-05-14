class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //svi no ka each digit p set bits(1) check kro
        // if (nums[i] & (1<<i) !=0 )  -> left shif
        //     cnt_1++;
        // for every bit position:
            //cnt how many numbers have 0
            //cnt how many numbers have 1

        //Since, most numbers appear 3 times, their bits contribute in 
        //multiple of 3.
        // If at any bit position the count of 1s % 3 == 1, it means that 
        //bit belongs to the unique number. 

        int ans = 0;
        for(int i=0;i<32;i++){  //check each bit positn from 0 to 31.
            int cnt_1 =0;       //no of set bits at ith positin
            for(auto it: nums){  //al no ka ith bit chk
                if((it & (1<<i)) !=0)  //check if ith bit is set
                    cnt_1++;
            }
            //ith bit ka cnt_1 hai apn ps:
            if(cnt_1 % 3 == 1)    //single no
                ans = ans | (1<<i);  //us postion pe set bit daldo    
        }
        return ans;
    }
};