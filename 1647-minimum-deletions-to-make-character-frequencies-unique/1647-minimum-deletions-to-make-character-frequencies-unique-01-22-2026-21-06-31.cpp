class Solution {
public:
    int minDeletions(string s) {
        //jo bol rha wo krdo
        //abcdabcd -> o/p  = 5 ; only 3 char bachenge
        vector<int> freq(26,0);
        unordered_set<int> st; //konsi freq used kr chuke
        int ans = 0;
        for(auto it: s){
            freq[it-'a']++;
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0 && st.find(freq[i]) !=st.end()){ //freq aa chuka already
                freq[i]--;
                ans++;
            }
            st.insert(freq[i]);  
        }
        return ans;

    }
};