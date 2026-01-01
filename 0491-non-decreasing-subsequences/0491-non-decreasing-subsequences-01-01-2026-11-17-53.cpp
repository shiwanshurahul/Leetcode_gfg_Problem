class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
int n;
void solve(vector<int>&nums, int idx){
    if(temp.size()>=2)
            ans.push_back(temp);
    if(idx>=n)
        return;   //out of bound 
    unordered_set<int> st;    
    for(int i=idx;i<n;i++){ //idx se n tak -> (0->2 -> 1->2 -> 2->2)
        if( (st.find(nums[i]) == st.end()) && (temp.empty() || nums[i]>=temp.back()) ){
            temp.push_back(nums[i]);
            solve(nums,i+1);  //idx+1 tha letter combn wale me
            //after this recursion:
            temp.pop_back();
            st.insert(nums[i]); //use hai curr me -> same as permutn 2
        }
    }
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //all possible combint/permutan -> backtrackin
        //If choices = many / variable → loop + 1 recursive call
         //idx+1 tha letter combn wale me as usme dusre ke sath combn rq tha
        n = nums.size(); 
        solve(nums,0);
        return ans;
    } // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
};