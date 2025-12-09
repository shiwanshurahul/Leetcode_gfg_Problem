class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          sort(strs.begin(),strs.end());
        int n =strs.size();
        int u =strs[0].length();
        int i=0,cnt =0;
        while(i<u &&strs[0][i]==strs[n-1][i] ){
        cnt++;
        i++;
        }
        return strs[0].substr(0,cnt);
    }
};