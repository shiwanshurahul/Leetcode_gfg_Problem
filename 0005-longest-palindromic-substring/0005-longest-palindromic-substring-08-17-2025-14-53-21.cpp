class Solution {
public:
bool checkpalindrom(string &s,int i ,int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;j--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
    string longestPalindrome(string s) {
        //sare substring lelo from all char's 
        if(s.empty())
        return "";
        string ans="";
        int len =0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(checkpalindrom(s,i,j)){
                    if(len < j-i+1){
                        len =j-i+1;
                        ans =s.substr(i,j-i+1);  //j-i+1 =length
                    }
                }
            }
        }
         return ans; 
    }
};