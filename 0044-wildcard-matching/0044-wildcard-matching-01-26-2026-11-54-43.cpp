class Solution {
public:
bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
    if(i< 0 && j < 0)  //dono sath me
        return true;  
    
    if(i>=0 && j<0)  //string bacha hai -> s="aa", p ='"a"
        return false;

    if(i< 0 && j>=0){ //string khatam hai but pattern bacha hai -> s="a", p = "**a"
        while(j>=0){
            if(p[j] !='*')  //check sirf * reh skta 
                return false;
            j--;    
        }
        return true;
    }     

    if(dp[i][j] !=-1)
        return dp[i][j];  

    if(s[i]==p[j] || p[j]=='?')
        return dp[i][j] = solve(s,p,i-1,j-1,dp);
    else if(p[j]=='*')
        return dp[i][j] = solve(s,p,i,j-1,dp) || solve(s,p,i-1,j,dp);//* = *a lelo 
    else
        return false;       
}
    bool isMatch(string s, string p) {
        //famous quest   '?' -> match/replace single char   e.g. a
        // '*' -> matches/replaces seq of char/string e.g abc, *a, *aa, *aaa, empty string
        vector<vector<int>> dp(s.length()+1, vector<int> (p.length()+1, -1));
        return solve(s,p,s.length()-1,p.length()-1, dp);
    }
    //valid -> s[i] == p[j] -> solve(i-1,j-1,s,p);
    //      -> p[j] = '?'  -> solve(i-1,j-1,s,p);
    //      -> p[j] = '*' -> kuch v bana skta  //2 cases-> 1. '' man lo = solve(i,j-1,s,p);  2. *s[i] man lo = solve(i-1,j,s,p)
    //e.g. s = a b c d e
    //     p = a * c ? e
    //        * ko *b man liya tmne = can take as your req len of string
};
//aa a* -> i,j-1 || i-1,j