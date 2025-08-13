class Solution {
public:
int dp[101];
int solve(string s, int i, unordered_map<string, char> &mp){
    
    if(i== s.length())
        return 1;

    string temp=""; 
    temp += s[i];    
    
    if(mp.find(temp) ==mp.end())           //s[i] =='0' v dal skte but wo temp handle kr lega
        return 0; 

    if(dp[i] != -1)
        return dp[i];

    int pick_1 =0;
    int pick_2 =0;

    pick_1 = solve(s, i+1, mp);
    if(i+1< s.length() && stoi(s.substr(i,2)) <=26 ){   // && s[i]!='0' laga skte but temp dekh lega
        pick_2 = solve(s, i+2 , mp); //len 1 hi ja rha substring
    }
    return dp[i] = pick_1 + pick_2;
}
    int numDecodings(string s) {

        unordered_map<string, char> mp;
        char ch= 'A';
        for(int i=1;i<27;i++){
            string str = to_string(i);
            mp[str] = ch++;
        }
        // mp["1"] = 'a';   mp["2"] = 'b';  mp["3"] = 'c';
        // mp["4"] = 'd';   mp["5"] = 'e';  mp["6"] = 'f';
        // mp["7"] = 'g';   mp["8"] = 'h';  mp["9"] = 'i';
        // mp["10"] = 'j';  mp["11"] = 'k';  mp["12"] = 'l';
        // mp["13"] = 'm';   mp["14"] = 'n';  mp["15"] = 'o';
        // mp["16"] = 'p';   mp["17"] = 'q';  mp["18"] = 'r';
        // mp["19"] = 's';   mp["20"] = 't';  mp["21"] = 'u';
        // mp["22"] = 'v';   mp["23"] = 'w';  mp["24"] = 'x';
        // mp["25"] = 'y';   mp["26"] = 'z';

        memset(dp,-1, sizeof(dp));
        return solve(s, 0,mp);
        //pick krna hai ya toh 1 len ya toh 2 len, skip ka no optio
    }
};