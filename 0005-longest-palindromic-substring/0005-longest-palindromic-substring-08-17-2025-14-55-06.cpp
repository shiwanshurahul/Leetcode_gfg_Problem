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
        int n =s.length();
        int maxi = 1;
        string ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                  if(maxi <j-i+1 && is_palindrome(s,i,j)){
                        maxi = j-i+1;
                        ans = s.substr(i,maxi);
                }
            }
        }
        return ans;
    }
};