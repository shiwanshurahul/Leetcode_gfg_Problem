class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int mx =-100;
        if(s.length()==0)
            return 0;
        unordered_map<char,int> mp;

        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()<j-i+1){  // duplicates hai mp me
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            else if(mp.size()==j-i+1){
                mx= max(mx,j-i+1);
                j++;
            }
        }
        return mx;
    }
};