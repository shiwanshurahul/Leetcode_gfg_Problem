class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    int solve(vector<int> &candidates, int target, int i){
        if(i>= candidates.size() || target<0)
            return 0;
        if(target==0){
            ans.push_back(v);
            return 1;
        }
        
        v.push_back(candidates[i]);
        int pick = solve(candidates,target-candidates[i], i);  //firse choose kr skte
        
        v.pop_back(); //after prev recursive call
        int skip = solve(candidates,target,i+1);  //skip
        return pick + skip;
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cout<<solve(candidates, target, 0);
        return ans;
    }
};