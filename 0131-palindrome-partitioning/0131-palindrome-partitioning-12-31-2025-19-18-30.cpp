class Solution {
public:
bool ispalindrom(string &s,int st,int e){
    while(st<=e){
        if(s[st]!=s[e])
        return false;
        st++;e--;
    }
    return true;
}
void backtrack(int idx,string &s,  vector<vector<string>> &ans,vector<string>&path){
    if(idx==s.length()){
        ans.push_back(path);
        return;
    }
    for(int i =idx;i<s.length();i++){
      if(ispalindrom(s,idx,i)){
          path.push_back(s.substr(idx,i-idx+1));
          backtrack(i+1,s,ans,path);
          path.pop_back();
      }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(0,s,ans,path);
        return ans;
    }
};