class Solution {
public:
    int minSteps(string s, string t) {
        //dono ka cnt of char lelo
        vector<int> s_cnt(26,0), t_cnt(26,0);

        if(s.length() != t.length())
            return 0;

        for(int i=0;i<s.length();i++){
            s_cnt[s[i]-'a']++;
            t_cnt[t[i]-'a']++;
        }
        if(s_cnt == t_cnt) //already an anagram
            return 0; 
        
        int cnt=0;
        for(int i=0;i<26;i++){
            if(s_cnt[i] > t_cnt[i])
                cnt += s_cnt[i]-t_cnt[i];
        }
        return cnt;

    }
};