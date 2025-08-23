class Solution {
public:
int solve(vector<int> &nums, int i, int prev){
    if(i >= nums.size())
        return 0;

    int a = -1;
    int b = -1;

    if(prev == -1 || nums[i] > nums[prev]){
        a = 1 + solve(nums,i+1,i);   //1 len added
        b = solve(nums,i+1,prev);   //choice
    }
    else{
        b = solve(nums,i+1,prev);    
    }
    return max(a,b);    

}
    int lengthOfLIS(vector<int>& nums) {
        //famous type
        return solve(nums,0,-1);
    }
};