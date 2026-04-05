class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //k=10 -> fixed size slidin window
        //10 size string pe sliding window lagao = 10 se jyada size ni jane do
        unordered_map<string, int> mp;
        int i=0,j=0;
        vector<string> ans;
        string curr="";
        while(j< s.length()){
            curr+=s[j];
            if(j-i+1 <10){
                j++;
            }
            else if(j-i+1 ==10){  //curr v 10 size ka
                if(mp[curr] == 1){   //already exis
                    ans.push_back(curr);
                }
                mp[curr]++;  //mp rhega string ko slide kro
                curr.erase(0,1);      //remove calc for i
                i++;                  //slide windo
                j++;
            }
        }
        
        return ans;
    }
};