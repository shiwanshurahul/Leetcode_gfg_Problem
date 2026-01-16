class Solution {
public:
    string minWindow(string s, string t) {
        //continuous ni hai -> anagram wala ni ki t ke size jitna fixed window size bnake iterate
    //mp me 't' rkhlo and cnt_req var rkhlo (freq v track krlega)
    //jaise hi char mila 's' me jo 't' me hai & cnt_req!=0 hai toh mp[ch]-- kro
    //cnt_req = 0 hai toh sare char mil chuke = is window ka len store
    // and try ki ye shrink ho until cnt_req is 0 with i
        int n = s.length();
        unordered_map<char,int> mp;
        int cnt_req = t.length();
        int ans = 1e9;
        for(auto it:t){
            mp[it]++;
        }  //mp -> ABC

        int start_i = 0;
        int i=0,j=0;

        while(j<s.length()){
            if(mp[s[j]] > 0)
                cnt_req--;
            mp[s[j]]--;  //sare char
            while(cnt_req==0){
                //shrink until cnt_req is 0 
                if(j-i+1 < ans ){
                    ans = j-i+1; //curr winodow size
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                    cnt_req++;
                i++;  
            }
            j++;  
        }
        return ans==1e9 ? "" : s.substr(start_i,ans);

    }
};