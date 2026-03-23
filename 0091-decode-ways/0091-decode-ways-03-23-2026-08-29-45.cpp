class Solution {
public:
unordered_map<string, char>mp;
int solve(string s, int i, vector<int> &dp){
    if(i>=s.length())   
        return 1;  //1 way mila

    if(dp[i] !=-1)
        return dp[i];

    string temp = "";
    temp+= s[i]; //single_len ke via

    if(mp.find(temp) == mp.end() ) //0 wala case handle ->seedha s[i] krte but map me string 
        return 0;     //06 -> 0th idx se seedha 0 return to main, fir no execution

    int single_len = 0;
    int two_len = 0;

    single_len = solve(s,i+1, dp);  //i+1 wala check kro ->ek ek char krke i==n tak pahuncho fir backtrack krke 2 len wale check
    //i,i+1 = 2 len me check
    if(i+1<s.length() && stoi(s.substr(i,2)) <27 )  //valid   
        two_len = solve(s,i+2, dp); //i+2 only if valid hai
        
    return dp[i] = single_len + two_len;     
}//har recursive call pe check 1 hi char ho rha
    int numDecodings(string s) {
        char ch = 'A';

        for(int i=1;i<=26;i++){
            mp[to_string(i)] = ch;
            ch++;  //'B', 'C', ..
        }
        //0 ni hai isme
        vector<int> dp(s.length()+1,-1);
        return solve(s,0, dp); //1 len and 2 len check
    }
};// recursion returns to the most recent function call (top of the call stack), and executes pop_back() there first.

// Why this happens (core concept)
// When a function returns, execution resumes exactly after the function call line in the same stack frame.
//simple recursion me v aisa hota
