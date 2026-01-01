class Solution {
public:
vector<vector<string>> ans;
vector<string> temp;
bool is_palindrom(int s, int e, string &str){
    while(s<=e){
        if(str[s]!= str[e])
            return false;
        s++;
        e--;    
    }
    return true;
}
void solve(string &s, int idx, int n){
    if(idx>=n){
        ans.push_back(temp);
        return;
    } 

    for(int i=idx;i<n;i++){
        if(is_palindrom(idx,i,s)){  //idx se i tak tbhi partition kro
            temp.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,n);  //idx+1 tha letter combn wale me
            //after recusvie call: (mostly solve(i+1) wale hi hota)
            temp.pop_back();
        }
    } 
}
    vector<vector<string>> partition(string s) {
        //all possible combint/permutan -> backtrackin
        //If choices = many / variable → loop + 1 recursive call
        solve(s,0,s.length());
        return ans;
    }  //letter combint of phone number
    //idx rehta & i+1 pe next recursiv call taki idx se i tak check kr ske 
    
        // recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
};
//for loop chlega 0->2 -> 1->2 -> 2->2
//                  |        │
//                  |       2->2
//                  1->2
//                  2->2
// solve(0) | []
// │
// ├── i=0 → "a"
// │   temp = ["a"]
// │   solve(1)
// │   │
// │   ├── i=1 → "a"
// │   │   temp = ["a","a"]
// │   │   solve(2)
// │   │   │
// │   │   ├── i=2 → "b"
// │   │   │   temp = ["a","a","b"]
// │   │   │   solve(3)  ✅ BASE
// │   │   │   → ["a","a","b"]
// │   │   │
// │   │   └── backtrack → pop "b"
// │   │
// │   └── i=2 → "ab" ❌ (skip)
// │
// ├── backtrack → pop "a"
// │
// ├── i=1 → "aa"
// │   temp = ["aa"]
// │   solve(2)
// │   │
// │   ├── i=2 → "b"
// │   │   temp = ["aa","b"]
// │   │   solve(3)  ✅ BASE
// │   │   → ["aa","b"]
// │   │
// │   └── backtrack → pop "b"
// │
// ├── backtrack → pop "aa"
// │
// └── i=2 → "aab" ❌ (skip)
