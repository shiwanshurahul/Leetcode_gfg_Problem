class Solution {
public:
bool  solve(int idx,string s, unordered_set<string> st){
     if(idx>=s.length()){
       return true;
     }
     if(st.find(s)!=st.end())
     return true;// no todna

    for(int i=0;i<s.length();i++){//l,le,lee,leet->  
        string temp =s.substr(idx,i);//each length ka check i.e 1,2,3,4,
        if(st.find(temp)!=st.end() && solve(idx+i,s,st))
        return true;
    }///pehle st.find fir dusra statement dekhege if wala
    return false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
          for(auto it: wordDict){
              st.insert(it);
          }

     return solve(0,s,st);   
    }
};