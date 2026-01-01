class Solution {
public:
int ans = 0;
bool check_net_change(vector<int> &change){
    for(auto it: change){  //sb zero ho
        if(it != 0)
            return false;
    }
    return true;
}
void solve(vector<vector<int>>& requests,int i, int cnt, vector<int> &change){
    if(i>=requests.size()){
        if(check_net_change(change))
            ans = max(ans,cnt);
        return;
    }

    int from = requests[i][0];
    int to = requests[i][1];

    change[to]++;
    change[from]--;
    solve(requests, i+1, cnt+1, change);
    //after recursive call:

    change[to]--;   //backtrack
    change[from]++;
    solve(requests, i+1, cnt, change);  

}
    int maximumRequests(int n, vector<vector<int>>& requests) {
        //all possible combint/permutan -> backtrackin
        //If choices = many / variable → loop + 1 recursive call
        //pick then explore then skip then explor
        // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

        // Why this happens (core concept)
        // When a function returns, execution resumes exactly after the function call line in the same stack frame.
    //simple recursion me v aisa hota
    //har point pe pick, skip ka option

        vector<int> change(n,0); //isme store krenge to and from
        solve(requests,0,0,change);
        return ans;
    }
};