class Solution {
public:
bool solve(int idx, string &s, int n, unordered_set<string> &st, vector<int> &dp){
    if(idx >=n)
       return true;

    if(st.find(s) != st.end())  //mt kro aur break
        return true;

    if(dp[idx] !=-1)
        return dp[idx];   
     
    for(int i=0;i<s.length();i++){//l,le,lee,leet->  i=1=1 se v suru kr skte
        string temp =s.substr(idx,i);//each length ka check i.e 1,2,3,4,
        if(st.find(temp)!=st.end() && solve(idx+i, s, n,st, dp))
        return dp[idx] = true;
    }///pehle st.find fir dusra statement dekhege if wala
     return dp[idx] = false;  
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return solve(0, s, s.length(), st, dp);
        
    }
};