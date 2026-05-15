class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //moore voting algo
        //jo n/2 se jyad a rha wo sbko cance kr dega
        int max_occ = nums[0];
        int cnt = 1; //max_occ ka cnt
        int i=1;
        while(i<nums.size()){
            if(cnt==0){
                max_occ = nums[i];  //jo v elem ha
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