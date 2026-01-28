class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //i<j<k
        //brute force -> o(n^3) -> tle
        //lis lga skte
        //sbse pehle num1 ko set
        long long num1 = 1e12; //smallest
        long long num2 = 1e12; 
        int curr = 0; //isse iterate krenge -> largest
        for(int i=0;i<nums.size();i++){
            curr = nums[i];
            if(curr<=num1) //num1 ko smallest banao
                num1 = curr;    //set
            else if(curr>= num1 && curr<=num2 ) //num1 already set hai
                num2 = curr;    // intermediate bana rhe  
            else         // num1<num2 && num2<curr
                return true;
        }
        return false;
    }
};