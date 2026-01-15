class Solution {
public:
bool isconcatenated( string word,unordered_set<string>&st){
    for(int i=0;i<word.length();i++){
        string prefix =word.substr(0,i+1);
        string suffix =word.substr(i+1);
        if(st.find(prefix)!= st.end() && st.find(suffix)!=  st.end())
        return true;
        else if(st.find(prefix)!= st.end()  && isconcatenated(suffix,st))
        return true;
    }
    return false;
}
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       int n =words.size();
       unordered_set<string> st(begin(words),end(words));
       vector< string> ans;
       for(int i=0;i<n;i++){
           string word = words[i];
           if(isconcatenated(word,st))
           ans.push_back(word);
       }
       return ans;
    }
};