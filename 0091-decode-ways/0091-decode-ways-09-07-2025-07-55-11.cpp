class Solution {
public:
unordered_map<string, char>mp;
int solve(string s, int i, vector<int> &dp){
    if(i>=s.length())   
        return 1;

    if(dp[i] !=-1)
        return dp[i];

    string temp = "";
    temp+= s[i];

    if(mp.find(temp) == mp.end() )   //0 wala case handle -> seedha s[i] krte but map me string req hai
        return 0;    

    int single_len = 0;
    int two_len = 0;

    single_len = solve(s,i+1, dp);    //i+1 wala check
    if(i+1<s.length() && stoi(s.substr(i,2)) <27 )
        two_len = solve(s,i+2, dp); //i+2 only if valid hai

    return dp[i] = single_len + two_len;     
}//har recursive call pe check 1 hi char ho rha
    int numDecodings(string s) {
        char ch = 'A';

        for(int i=1;i<=26;i++){
            mp[to_string(i)] = ch;
            ch++;
        }
        //0 ni hai isme
        vector<int> dp(s.length()+1,-1);
        return solve(s,0, dp); //1 len and 2 len check
    }
};