class Solution {
public:
    string removeDuplicateLetters(string s) {
        //smalles in lexigraphicl order: abc < bca <cab < cba
        //monotonic st
        //"bcabc" -> "abc"
        //"cbadcdbc" -> "acdb"
        //"bcab" -> "bca"
        //ans.back() < s[i] = tbhi smallest ho skta e.g. a < b

        //logi: agar koi lexicographica greatr char bad me a rha toh 
        //usko curr hata do ans me se and bad me wo aega
        // e.g. bcabc -> bc bad me a rh = smalles is abc

        // 1 -> sare char ka las idx stor
        // 2 -> ans.back() > curr_ch and ans.back() bad me a rha toh remove it
 
        int n = s.length();
        vector<int> taken(26,0);  //abtak
        vector<int> last_idx(26,0); //sbka last occurence e.g. b->3,c->4
        string ans;
        for(auto i=0;i<n;i++){
            char ch = s[i];
            last_idx[ch-'a'] = i;  //sbka last occurenc stor
        }   //'b'=1->3, 'c'=2->4,'a'=0->2

        for(int i=0;i<n;i++){
            int idx = s[i]-'a';
            if(taken[idx])
                continue;
            //smallest ni hai ans me:
            // e.g. ans='b', s[i] ='a' and 'b' bad me aa rha 
            while(!ans.empty() && ans.back() > s[i] && last_idx[ans.back()-'a'] > i ){   //last_idx me fir se age a rh ans.back() = remove curr ans.back()
                taken[ans.back()-'a'] = 0;  //c ka 0, b ka 0
                ans.pop_back(); 
            }
            ans+=s[i];  //'b' , 'bc', 'a', 'ab' , 'abc' 
            taken[idx] = 1;  
        }
        return ans;
    }
};