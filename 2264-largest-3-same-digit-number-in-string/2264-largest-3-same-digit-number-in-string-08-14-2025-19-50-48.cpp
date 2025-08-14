class Solution {
public:
    string largestGoodInteger(string num) {
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        string ans="";

        while(j< num.length()){
            mp[num[j]]++;
            if(j-i+1 <3){
                j++;
                continue;
            }
            else if(j-i+1 ==3){  //3 ke aage mt jane do
                if(mp.size() ==1 && num[j] ==num[i]){
                    ans+= num[j]; ans+= num[j]; ans+= num[j];
                    return ans;
                }
                while(mp.size() > 1){
                    mp[num[i]]--;

                    if(mp[num[i]] == 0)
                    mp.erase(num[i]);
                    i++;
                }
                j++;  //har bar
            }
        }
        return "";
    }
};