class Solution {
public:
bool check_freq_substr(vector<int>& freq){ 
    //freq can be 0 or same for all non zero
    int x = 0;
    for(int i=0;i<26;i++){
        if(freq[i] == 0)
            continue;
        else if(x == 0)
            x = freq[i];    
        else if(freq[i] != x)  //diff freq than x
           return false;   
    }
    return true;   //equal freq
}
    int longestBalanced(string s) {
        //similar as 3719
        //constrain km hai = brute forc
        // all distinct characters in the substring appear the same
        // number of times.
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0); //each i to j me check
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(check_freq_substr(freq)) 
                    ans = max(ans, j-i+1);
            }   
        }
        return ans;
    }
};