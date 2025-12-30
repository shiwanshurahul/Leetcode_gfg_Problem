class Solution {
public:
vector<vector<int>> ans;
void solve(int i,int k,int n, vector<int> &v){
    if(k==0 && n==0 ){
        ans.push_back(v);
        return;
    }
    if(i>n ||k==0 || i>9)
    return;
    solve(i+1,k,n,v); //skip
    v.push_back(i);  //pick
    solve(i+1,k-1,n-i,v);
    v.pop_back();  //backtrack
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
         solve(1,k,n,v);
         return ans;
    }
};