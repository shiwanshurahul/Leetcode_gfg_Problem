class Solution {
public:
vector<string>ans;
void solve(int idx,string &digits, unordered_map<char,string> mp,string &temp){
            if(idx>=digits.size()){
                ans.push_back(temp);
                return;
            }
            char ch = digits[idx]; //'2'; '3' ; '2' ->digt = "232"
            string s = mp[ch];      //"abc"; "def" ; "abc"
            for(int i=0;i<s.size();i++){  
                temp.push_back(s[i]); //'a' ;'d' ; 'a'
                solve(idx+1,digits,mp,temp);//idx ke liye hi krenge -> taki combo aye  'ad', 'ae', 'af','bd'..
                temp.pop_back();   //backtrack
            }
   }   
    vector<string> letterCombinations(string digits) {
        //all posible combintn -> backtracki
        //for loop me backtrack -> most used -> 1 recursive call
        //If choices = many / variable → loop + 1 recursive call
        //131 kro
        if(digits.length()==0)
            return ans;
        unordered_map<char,string> mp;
        mp['2'] ="abc";
        mp['3'] ="def";
        mp['4'] ="ghi";
        mp['5'] ="jkl";
        mp['6'] ="mno";
        mp['7'] ="pqrs";
        mp['8'] ="tuv";
        mp['9'] ="wxyz";
        string temp ="";
        solve(0,digits,mp,temp); //0-> idx for traversing over digits
        return ans;
    }//do do char ke combinat chahiy for digits= '23' = ek string pe iterate and call for another = 'ad', .. 
// e.g.2.  digits= "232"
// Output
// ["ada","adb","adc", .. 3 ka combint
//sare digits pe ek sath traverse krke try
//for digits="23" -> "ad","ae","af",.. aise bnega

// solve(0, "")
//  └─ push 'a'
//     solve(1, "a")
//      └─ push 'd'
//         solve(2, "ad")  ✅ base case
//         pop 'd'
//      └─ push 'e'
//         solve(2, "ae")
//         pop 'e'
//      └─ push 'f'
//         solve(2, "af")
//         pop 'f'
//     pop 'a'

// before popping 'd' or 'e' or 'f' don;t u think call stk skould go to 'a' then execute the pop_back line there?
// Short answer (important)

// ❌ No, control does NOT jump directly back to 'a'’s frame.
// ✅ It returns to the most recent function call (top of the call stack), i.e., the solve(1, "a") frame, and executes pop_back() there first.

// Why this happens (core concept)

// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota

// Let’s trace "ad" line-by-line
// 1️⃣ We are inside this loop ( digit '3')
// temp.push_back('d');      // temp = "ad"
// solve(2, digits, mp, temp); -> base case = return
// temp.pop_back();          // ← THIS LINE runs first after return

//bina for loop:
// temp.push_back('a');
// solve(idx+1);
// temp.pop_back();

// temp.push_back('b');
// solve(idx+1);
// temp.pop_back();

// temp.push_back('c');
// solve(idx+1);
// temp.pop_back();




// Without loop → you must write 2 (or more) recursive calls

// With loop → one recursive call is enough, loop handles branching

// Case 1️⃣ Plain Backtracking (NO loop)

// Example: include / exclude (subsets)

// void solve(int idx) {
//     if (idx == n) {
//         ans.push_back(curr);
//         return;
//     }

//     // choice 1: include
//     curr.push_back(arr[idx]);
//     solve(idx + 1);
//     curr.pop_back();

//     // choice 2: exclude
//     solve(idx + 1);
// }

// Why 2 recursive calls?

// Because at each index you have two explicit choices:

// take the element
// don’t take the element

// Each choice must be explored separately → 2 recursive calls
// 👉 This forms a binary recursion tree

//             []
//          /      \
//       [1]       []
//      /   \     /   \

// Case 2️⃣ Backtracking WITH for loop

// Example: letter combinations

// void solve(int idx) {
//     string s = mp[digits[idx]];
//     for (char c : s) {
//         temp.push_back(c);
//         solve(idx + 1);
//         temp.pop_back();
//     }
// }

// Why only 1 recursive call?

// Because:

// The loop itself iterates through all choices
// Each loop iteration represents one branch
// Recursion only moves to the next level


};