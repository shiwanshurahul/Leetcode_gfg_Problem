class Solution {
public:
int solve(vector<int> &nums, int target, int i){
    if(target == 0)  //1 combination mila
        return 1;
        
    if(i>= nums.size() || target<0)
        return 0;

    int pick = solve(nums,target-nums[i],0);  //firse pick kr skte from start
    int skip = solve(nums,target,i+1);

    return pick + skip;    //no of ways bata rha

}
    int combinationSum4(vector<int>& nums, int target) {
        //combination me cnt ni req hai toh 1 + solve(..) ki no need
        return solve(nums,target,0);
    }
};