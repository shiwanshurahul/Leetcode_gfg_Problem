class Solution {
public:
int solve(vector<int>& nums, int i){
    if(i>= nums.size()-1)
        return 1;

    for(int j=1;j<=nums[i];j++){
        if(solve(nums,i+j))
            return 1; 
    } 
    //last me if true ni mila toh
    return 0;

}
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};