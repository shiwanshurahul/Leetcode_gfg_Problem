class Solution {
public:
void backtrack(int idx, vector<int> &curr,  vector<vector<int>> & ans,vector<int>& nums,int n){
 if(curr.size()>=2)
  ans.push_back(curr);

  unordered_set<int> st;
 for(int i=idx;i<n;i++){
if((curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])== st.end())){
    curr.push_back(nums[i]);
    backtrack(i+1,curr,ans,nums,n);

    curr.pop_back();
    st.insert(nums[i]);
}
}

}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n =nums.size();
        backtrack(0,curr,ans,nums,n);
        return ans;
    }
};