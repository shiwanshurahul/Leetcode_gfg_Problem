class Solution {
public:
bool solve(int idx, string &s, int n, unordered_set<string> &st, vector<int> & dp){
    if(idx >=n)
       return true;  //last tak pahunch gye

    if(st.find(s) != st.end())  //exists in set = mt kro aur break
        return true;

    if(dp[idx] !=-1)
        return dp[idx];   
     
    for(int i=1;i<s.length();i++){//l,le,lee,leet->  i=0 se v suru kr skte
        string temp =s.substr(idx,i);//each length ka check i.e 1,2,3,4,
        if(st.find(temp)!=st.end() && solve(idx+i, s, n,st, dp))
            return dp[idx] = true;
    }//pehle st.find idx se i tak fir recursive call idx+i se
    
    return dp[idx] = false;  
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return solve(0, s, s.length(), st, dp);
        }
};//akhiri idx tak pahunch gye toh return true
//solve(0) -> for(idx=0,i=1,temp='l' : idx=0,i=2,temp="le" : idx=0,i=3,temp="lee" : idx=0,i=4, temp="leet" -> in st =  solve(4) -> for(idx=4,i=1, temp="c" : idx=4,i=2,temp="co" : idx=4,i=3, temp="cod" : idx=4,i=4,temp="code" -> return true) -> return true )