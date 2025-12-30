class Solution {
public: //backtracking -> pick krke explore fir skip krke explore
    vector<vector<int>> ans;
    vector<int> v;
    void solve(vector<int> &candidates, int target, int i){
        if(i>= candidates.size() || target<0)
            return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        v.push_back(candidates[i]);
        solve(candidates,target-candidates[i], i);  //firse choose kr skte
        
        v.pop_back(); //after pick recursive call
        solve(candidates,target,i+1);  //skip
          //return pick + skip; void v rkh skte as ans chahiy   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
    // Without skip: We'd only consider combinations that include the current element (e.g., 2), and miss combinations that skip it (like [7]

//     Example Walkthrough: target = 7, candidates = [2, 3, 6, 7]
// Initial State
// v = [] (current combination)
// i = 0 (start at 2)
// target = 7
// Step 1: pick Branch (Use 2)
// v.push_back(2) → v = [2]
// target = 7 - 2 = 5
// Call solve(candidates, 5, 0)  // Reuse index 0 (allowing multiple 2s)
// Apply Code -> Inside solve(candidates, 5, 0):
// v = [2], i = 0, target = 5
// Pick 2 again:
// v.push_back(2) → v = [2,2]
// target = 5 - 2 = 3
// Call solve(candidates, 3, 0)  // Reuse index 0
// Apply Code -> Inside solve(candidates, 3, 0):
// v = [2,2], i = 0, target = 3
// Pick 2 again:
// v.push_back(2) → v = [2,2,2]
// target = 3 - 2 = 1 
// Call solve(candidates, 1, 0)  // Reuse index 0
// Apply Code -> Inside solve(candidates, 1, 0):
// Pick 2 again:
// v.push_back(2) → v = [2,2,2,2]
// v = [2,2,2,2,], i = 0, target = -1 -> → invalid (target < 0)
// Return 0 (no solution)
//..
// Apply Code -> Skip 2 (after popping 2):
// v.pop_back() → v = [2,2]
// Call solve(candidates, 3, 1)  // Move/skip to next index (3)
// Apply Code -> Inside solve(candidates, 3, 1):
// v = [2,2], i = 1, target = 3
// Pick 3:
// v.push_back(3) → v = [2,2,3]
// target = 3 - 3 = 0 → valid!
// ans.push_back([2,2,3])
// Return 1
// Apply Code
// After returning, v.pop_back() → v = [2,2]
// Return 1 (solution found)
// After returning, v.pop_back() → v = [2]
// Now try skip branch (from solve(candidates, 5, 0))
// Step 2: skip Branch (Skip 2)
// v.pop_back() → v = []  (after returning from pick branch)
// Call solve(candidates, 7, 1)  // Skip 2 → move to next index (3)
// Apply Code
// Inside solve(candidates, 7, 1):

// v = [], i = 1, target = 7
// Skip 3 (move to next index):
// Call solve(candidates, 7, 2)  // Skip 3 → move to 6
// Apply Code
// Inside solve(candidates, 7, 2):
// v = [], i = 2, target = 7
// Skip 6 (move to next index):
// Call solve(candidates, 7, 3)  // Skip 6 → move to 7
// Apply Code
// Inside solve(candidates, 7, 3):
// v = [], i = 3, target = 7
// Pick 7:
// v.push_back(7) → v = [7]
// target = 7 - 7 = 0 → valid!
// ans.push_back([7])
// Return 1
// Apply Code
// After returning, v.pop_back() → v = []
// Return 1
// After returning, v.pop_back() → v = [] (no change)
// Return 1
// Why skip is Critical
// Path	Without skip	With skip
// 2,2,3	✅ Found	✅ Found
// 7	❌ Missed	✅ Found
// Without skip: We'd never leave i=0 (always use 2), so [7] is never found.
// With skip: We skip 2, then skip 3, then skip 6, and finally pick 7 → [7] is found.

};