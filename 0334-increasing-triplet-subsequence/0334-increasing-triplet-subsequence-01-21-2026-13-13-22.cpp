class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //i<j<k
        //b.f -> o(n^3) -> tle
        //lis lga skte
        long long num1 = 1e12; //smallest
        long long num2 = 1e12; 
        int num3 = 0; //isse iterate krenge -> largest
        for(int i=0;i<nums.size();i++){
            num3 = nums[i];
            if(num3<=num1) //num1 ko smallest banao
                num1 = num3;    //set
            else if(num3>= num1 && num3<=num2 )  //num1 already set hai
                num2 = num3;    // intermediate bana rhe  
            else         // num1<num2 && num2<num3
                return true;
        }
        return false;
    }
};