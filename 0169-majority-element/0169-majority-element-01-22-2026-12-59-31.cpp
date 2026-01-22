class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting algo
        int max_occ = nums[0];
        int cnt = 1; //max_occ ka cnt
        int i=1;
        while(i<nums.size()){
            if(cnt==0){
                max_occ = nums[i];  //jo v element hai
                cnt = 1;
            }
            else if(max_occ !=nums[i]){
                cnt--;
            }
            else if(max_occ == nums[i]){
                cnt++;
            }    
            i++;    
        }
        return max_occ;
    }   
};