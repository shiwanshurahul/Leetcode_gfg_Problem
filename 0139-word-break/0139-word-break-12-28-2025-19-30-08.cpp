class Solution {
public:
int n;
bool solve(int idx, string &s, unordered_set<string> &st, vector<int> & dp){
    if(idx>=n)
        return true;

    if(st.find(s) !=st.end())
        return true; //exists in st = ab aage se dhundho

    if(dp[idx] !=-1)
        return dp[idx];

    for(int i=1;i<n;i++){  //0 se v kr skte
        string temp = s.substr(idx,i);
        if( st.find(temp) !=st.end() ){  //exists in set = next part check  
            if(solve(idx+i,s,st,dp))
                return dp[idx] = true;
        }     
    }

    return dp[idx] = false; //yahan aaya toh true ni mila        
}

    bool wordBreak(string s, vector<string>& wordDict) {
        //leetcode -> exists
        //catsandog -> og bachga last me  = false
        n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return solve(0, s, st, dp);
    }
}; //akhiri idx tak pahunchne ki kosis -> same as jump
//solve(0) -> for(idx=0,i=1,temp='l' : idx=0,i=2,temp="le" : idx=0,i=3,temp="lee" : idx=0,i=4, temp="leet" -> in st =  solve(4) -> for(idx=4,i=1, temp="c" : idx=4,i=2,temp="co" : idx=4,i=3, temp="cod" : idx=4,i=4,temp="code" -> return true) -> return true )