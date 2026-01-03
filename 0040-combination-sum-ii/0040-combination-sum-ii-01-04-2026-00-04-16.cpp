class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
int n;
unordered_set<int> st;
void solve(vector<int>&candidates, int target, int idx){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    
    if(idx>=n || target <0)
        return;

    for(int i=idx;i<n;i++){
        if(i> idx && candidates[i] == candidates[i-1])
            continue;   //ek elem se aa jaega  
        
        temp.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1);
        //after this recursio:
        temp.pop_back();
    }      
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //ek elem ek hi bar aa skta
        //temp me check mat dalo ki ==temp.end() bcz 116 is a solutn
        //st se check ki idx wapas na le 
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(candidates,target,0);
        return ans;
    }
};