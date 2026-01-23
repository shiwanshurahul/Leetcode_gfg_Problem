class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //famous quest
        //1 se n tak sum lana hai using nums
        //min no of patch(no) to make sum in the range (1 to n)
        //[1,3] , n=6 -> patch = 2 = [1,2,3] -> sum = 1 to n tk sare a rhe = o/p = 1

        //[1,2,2] , n=5 = no patch req 
        //[1,4], n=6 -> patch = 2 = [1,2,4]  = sum = 1,2,3,4,5,6 = o/p = 1 

        //jo max_reachable no hai avi tk usse 1 bde ko lo
        //e.g. nums= [1,4], n=6 -> 1 pe the toh 2 liya
        long long max_reach = 0; //avi tk kitna pahunche
        int patch = 0;
        int i=0;

        while( max_reach < n){  //n tk hi jana hai
            if(i<nums.size() && nums[i] <= max_reach+1){  //no patch rer
                max_reach += nums[i];
                i++; 
            }
            else{  //patch kro max_reach+1 no ko
                max_reach += (max_reach+1);
                patch++;
            }
        }
        return patch;


    }
};