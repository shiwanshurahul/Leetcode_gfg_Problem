class Solution {
public://jump game jaisa
int solve(vector<int> &nums, int i){
    if(i>=nums.size()-1)
        return 0;

   int temp = 1e9;  //har recursive call ka apna temp

    for(int j=1;j<=nums[i];j++){
        temp = min(temp, 1 + solve(nums,i+j));   
    }
  return temp;

}
    int jump(vector<int>& nums) {
        //min no of jumps 
        return solve(nums,0);  
    }
};