class Solution {
public:
    int findMin(vector<int>& nums) {
        //pivot idx
        int s=0,e =nums.size()-1;

        while(s<e){
            int mid =(s+e)/2;
            if(nums[mid]<nums[e])  //cn be a solutn
                e=mid;   //stor ans
            else
                s=mid+1;
        }
        return nums[s];
    }
};