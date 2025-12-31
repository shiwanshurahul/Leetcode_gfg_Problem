class Solution {
public:
vector<string>ans;
void solve(int idx,string &digits, unordered_map<char,string> mp,string &temp){
            if(idx>=digits.size()){
                ans.push_back(temp);
                return;
            }
            char ch = digits[idx];  //'2'; '3'
            string s = mp[ch];      //"abc"; "def"
            for(int i=0;i<s.size();i++){
                temp.push_back(s[i]); //'a' ;'d' 
                solve(idx+1,digits,mp,temp);//i toh bdh hi rha toh idx ke liye hi krenge
                temp.pop_back();   //backtrack
            }
   }   
    vector<string> letterCombinations(string digits) {
        //all posible combintn -> backtracki
        //for loop me backtrack -> most used -> 1 recursive call
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
// e.g.2  digits= "232"
// Output
// ["ada","adb","adc", .. 3 ka combint
};