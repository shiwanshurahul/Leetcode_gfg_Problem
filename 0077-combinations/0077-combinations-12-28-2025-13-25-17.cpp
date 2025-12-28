class Solution {
public:
//backtracking -> pick krke explore fir skip krke explore
vector<vector<int>> ans;
vector<int> temp;
void solve(int n,int k, int i){
    if(k==0){
        ans.push_back(temp);
        return;
    }
    if(i>n)
        return;

    temp.push_back(i);
    solve(n,k-1,i+1); //k-1 bcz i pick krke explore kiya
    //after recursive call:
    temp.pop_back();
    solve(n,k,i+1);  //skip hai i
}
void solve1(int n,int k, int i){
    if(k==0){
        ans.push_back(temp);
        return;
    }
      if(i>n)
        return;

    for(int i=1;i<=n;i++){
        temp.push_back(i);
        solve(n,k-1,i+1); 
        temp.pop_back();
    }    
}

    vector<vector<int>> combine(int n, int k) {
        // solve(n,k,1);
        solve1(n,k,1);  //with for loop
        return ans;
    }
};