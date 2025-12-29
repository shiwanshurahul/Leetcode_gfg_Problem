class Solution {
public: //backtracking -> pick krke explore fir skip krke explore
vector<vector<int>> ans;
vector<int> temp;
int n;
void solve(vector<int>&nums, int i){
    if(temp.size()==n ){
        ans.push_back(temp);
        return;
    }
    if(i>n)
        return;

    for(int i=0;i<n;i++){
        if(find(temp.begin(), temp.end(),nums[i]) == temp.end()){
            temp.push_back(nums[i]);
            solve(nums,i+1);          
            //after this recisiv call:
            temp.pop_back();
        }
    }
   
}
    vector<vector<int>> permute(vector<int>& nums) {
        //sare elem chahiye = for loop chalo 0 to n har bar and each elem ko pick ya ski 
        //for loop me backtrack -> 1 recursie call hota
        n = nums.size();
        solve(nums,0);  // -> solve(nums) v bhej skte as for loop hai
        return ans;
    }
};