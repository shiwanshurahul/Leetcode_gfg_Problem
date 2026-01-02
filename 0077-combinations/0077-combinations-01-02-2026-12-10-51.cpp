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
    //after recursive call -> pehle next line execut hota
    temp.pop_back();
    solve(n,k,i+1);  //skip hai i
}
void solve1(int n,int k, int idx){
    if(k==0){
        ans.push_back(temp);
        return;
    }
      if(idx>n)
        return;

    for(int i=idx;i<=n;i++){  //1 recursive call in for loop
        temp.push_back(i);
        solve(n,k-1,i+1); 
        //after recursie call ->base case reach hone pe next line execut
        temp.pop_back();
    }    
}
// It returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.

    vector<vector<int>> combine(int n, int k) {
        //all possible combinatn, permutat -> backtrackin
        //generally for loop se hi bnta
        //for loop me backtrack -> most used -> 1 recursive call
        //If choices = many / variable → loop + 1 recursive call
        // solve(n,k,1);
        solve1(n,k,1);  //with for loop
        return ans;
    }
//     Method 1: solve
// Parameters: n=3, k=2, i=1
// (Starts at 1, moves forward)

// Step-by-Step Execution
// Initial call: i=1, k=2, temp=[]
// Pick i=1: temp = [1]
// Call solve(3, 1, 2)
// → i=2, k=1, temp=[1]
// Pick i=2: temp = [1,2] → k=0 → ans = [[1,2]]
// After return: temp.pop_back() → temp=[1]
// Skip i=2: Call solve(3, 1, 3)
// → i=3, k=1, temp=[1]
// Pick i=3: temp = [1,3] → k=0 → ans = [[1,2], [1,3]]
// After return: temp.pop_back() → temp=[1]
// After return: temp.pop_back() → temp=[]
// Skip i=1: Call solve(3, 2, 2)
// → i=2, k=2, temp=[]
// Pick i=2: temp = [2]
// Call solve(3, 1, 3)
// → i=3, k=1, temp=[2]
// Pick i=3: temp = [2,3] → k=0 → ans = [[1,2], [1,3], [2,3]]
// After return: temp.pop_back() → temp=[2]
// After return: temp.pop_back() → temp=[]
// Skip i=2: Call solve(3, 2, 3) → i=3, k=2, temp=[]
// Pick i=3: temp = [3] → k=1 → Call solve(3, 1, 4) → i=4>n → return
// After return: temp.pop_back() → temp=[]
// After return: temp.pop_back() → temp=[]
// Result
// ans = [[1,2], [1,3], [2,3]] ✅
// (Correct combinations in increasing order)



//m-2:

// solve1(3, 2, 1)  // start=1
// │
// ├─ Pick 1 → temp=[1], call solve1(3, 1, 2) -> start=2 (next number)
// │   │
// │   ├─ Pick 2 → temp=[1,2] → k=0 → ans += [1,2] -> Valid
// │   │
// │   └─ Pick 3 → temp=[1,3] → k=0 → ans += [1,3]-> Valid
// │
// ├─ Skip 1 → Pick 2 → temp=[2], call solve1(3, 1, 3) -> start=3
// │   │
// │   └─ Pick 3 → temp=[2,3] → k=0 → ans += [2,3]-> Valid
// │
// └─ Skip 1,2 → Pick 3 → temp=[3], call solve1(3, 1, 4) → start>n → return
};