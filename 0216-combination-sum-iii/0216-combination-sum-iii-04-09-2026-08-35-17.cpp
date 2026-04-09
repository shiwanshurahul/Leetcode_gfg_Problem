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
    temp.pop_back();  //3 ko pop
    solve(k,n,i+1); //skip -> dusra no lenge 
}
    vector<vector<int>> combinationSum3(int k, int n) {
        //all possible valid combination = backtrackin
        //no for loop + 1 recursiv call bcz just pick or skip elem
        solve(k,n,1);  //max k digit 
        return ans;
    }//solve(3,7,1) i=1-> t[1] = solve(2,6,2) i=2-> t[1,2] = solve(1,4,3)
    // i=3-> t[1,2,3] = solve(0,1,4) i=4-> k=0 = retur to i=3
    //    pop = t[1,2] fr solve(1,4,4)  i=4->t[1,2,4] = solve(0,0,5) = stor
};