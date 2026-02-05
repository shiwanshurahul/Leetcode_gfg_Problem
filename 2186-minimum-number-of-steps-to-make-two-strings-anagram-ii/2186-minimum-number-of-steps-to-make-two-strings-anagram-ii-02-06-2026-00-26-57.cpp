class Solution {
public:
    int minSteps(string s, string t) {
        //leetcode coats
        //common words = coa = 3
        //8-3 + 5-3 = 2
        vector<int> cnt(26,0);

        for(auto it: s){
            cnt[it-'a']++;
        } 
        for(auto it: t){
            cnt[it-'a']--;
        }

        //cnt the common char:
        int ans = 0;
        for(auto it: cnt){
            ans += abs(it);
        }    
        return ans;

    }
};