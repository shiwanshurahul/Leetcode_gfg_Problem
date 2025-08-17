class Solution {
public:
bool is_palindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j])
            return 0;
            i++;j--;
    }
        return 1;
}
    string longestPalindrome(string s) {
       if(s.empty())
        return "";
        string ans="";
        int len =0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(is_palindrome(s,i,j)){
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