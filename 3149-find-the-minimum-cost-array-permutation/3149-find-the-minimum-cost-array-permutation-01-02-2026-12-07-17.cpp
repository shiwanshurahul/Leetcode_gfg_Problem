class Solution {
public:
int n;
int min_score = 1e9;
vector<int> ans;
void solve(vector<int>&nums, vector<int>&vis, vector<int>& perm, int score){
    if(score> min_score)
        return;
    if(perm.size() == n){
        score += abs(perm[n-1] - nums[perm[0]]); //last ka
        if(min_score > score){
            min_score = score;
            ans = perm;
        }
        return;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = 1;
            perm.push_back(i);
            int s = perm.size(); //{0,1} or {0,2} or ..
            solve(nums,vis, perm, score + abs(perm[s-2]-nums[perm[s-1]]));
            //after this recursion
            vis[i] = 0;  
            perm.pop_back();
        }
    }

}
    vector<int> findPermutation(vector<int>& nums) {
        //all possible combint/permutan -> backtrackin
        //If choices = many / variable → loop + 1 recursive call
        //pick then explore then skip then explore
        // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

        // Why this happens (core concept)
        // When a function returns, execution resumes exactly after the function call line in the same stack frame.
        //simple recursion me v aisa hota
        n = nums.size();
        vector<int> perm = {0};
        vector<int> vis(n,0);

        vis[0] = 1;
        solve(nums,vis,perm,0);
        return ans;
    }
};