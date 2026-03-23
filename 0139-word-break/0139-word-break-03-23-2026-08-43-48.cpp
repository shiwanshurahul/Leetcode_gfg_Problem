class Solution {
public:
int n;
bool solve(int idx, string &s, unordered_set<string> &st, vector<int> & dp){
    if(idx>=n)  //last idx tk pahunce
        return true;

    if(st.find(s) !=st.end())
        return true; //exists in st = ab aage se dhundho

    if(dp[idx] !=-1)
        return dp[idx];

    for(int i=1;i<n;i++){  //0 se v kr skte
        string temp = s.substr(idx,i);  //l, le, lee, leet -> st -> solve(4)-> 
        if( st.find(temp) !=st.end() ){  //exists in set = next part check  
            if(solve(idx+i,s,st,dp))  //last idx tak pahunche
                return dp[idx] = true;
        }     
    }

    return dp[idx] = false; //yahan aaya toh true ni mila        
}
// or if( st.find(temp) !=st.end() && solve(idx+i,s,st,dp) )  //next part pe call
//             return dp[idx] = true;
    bool wordBreak(string s, vector<string>& wordDict) {
        //akhiri idx tak pahunc ki kosis -> same as jump
        //leetcode -> exists
        //catsandog -> og bachga last me = false
        n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return solve(0, s, st, dp);
    }
}; 
//set me mile string = next index se fir check 
//solve(0) -> for(idx=0,i=1,temp='l' : idx=0,i=2,temp="le" : idx=0,i=3,temp="lee" : idx=0,i=4, temp="leet" (ye sb loop me hai recurs me ni) -> in st = solve(4) -> for(idx=4,i=1, temp="c" : idx=4,i=2,temp="co" : idx=4,i=3, temp="cod" : idx=4,i=4,temp="code" -> return true) -> return true )