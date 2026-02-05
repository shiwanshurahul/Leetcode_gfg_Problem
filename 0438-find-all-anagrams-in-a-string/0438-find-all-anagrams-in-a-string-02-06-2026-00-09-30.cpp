class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> ss(26,0);
        vector <int> pp(26,0);
        vector <int> ans;
        if(p.size()>s.size())
            return ans;
        for(int i=0;i<p.size();i++){
            ss[s[i]-'a']++;
            pp[p[i]-'a']++;
        }
        if(pp==ss)
            ans.push_back(0);
        for(int i=p.size();i<s.size();i++){
            ss[s[i]-'a']++;  //ss['e' -'a'] =ss[4] =1
            ss[s[i- p.size()]-'a']--; // ss[[3-3]-'a']-- = ss[s[0]-'a']--   = ss['c'-'a']-- =ss[2]-- = sliding the window
                if(ss==pp)
                    ans.push_back(i+1 -p.size());  //starting idx chahiye
        }
        return ans;
    }
};