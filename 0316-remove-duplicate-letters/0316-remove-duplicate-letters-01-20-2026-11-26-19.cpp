class Solution {
public:
    string removeDuplicateLetters(string s) {
        //smallest in lexigraphical order: abc < bca 
        //monotonic st
        //"bcabc" -> "abc"
        //"cbadcdbc" -> "acdb"
        //"bcab" -> "bca"
        //ans.back() < s[i] = tbhi smallest ho skta e.g. a < b
        //aur koi char already visit hai toh check ki wo remove kre ya curr char
        //bad wala occuring ka idx daldo and pehle wala idx replace
        int n = s.length();
        vector<int> taken(26,0);  //abtak
        vector<int> last_idx(26,0); //sbka last occurence e.g. b->3,c->4
        string ans;
        for(auto i=0;i<n;i++){
            char ch = s[i];
            last_idx[ch-'a'] = i;  //sbka last occurence store
        }

        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(taken[idx])
                continue;
            //smallest ni hai ans me:e.g. ans='b', s[i] ='a' and 'b' bad me aa rha 
            while(!ans.empty() && ans.back() > s[i] && last_idx[ans.back()-'a'] > i ){   //last_idx me fir se hai s[i] = bad me aa rha = remove
                taken[ans.back()-'a'] = 0;
                ans.pop_back(); 
            }
            ans+=s[i];  
            taken[idx] = 1;  
        }
        return ans;
    }
};