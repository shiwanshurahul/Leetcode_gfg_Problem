class Solution {
public:
vector<vector<int>> ans;
vector<int> temp;
void solve(int k, int n, int i){
    if(n==0 && k==0){
        ans.push_back(temp);
        return;
    }
    if(k==0 || i>9 || n <0)
        return;
    
    temp.push_back(i); //pick
    solve(k-1,n-i,i+1);
    temp.pop_back();
    solve(k,n,i+1); //skip
}
    vector<vector<int>> combinationSum3(int k, int n) {
        //all possible valid combinations = backtracking
        solve(k,n,1);
        return ans;
    }
};