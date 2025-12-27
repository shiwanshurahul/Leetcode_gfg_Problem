class Solution {
public:
bool check_palindrome(string s,int i, int j){
    while(i<j){
        if(s[i]==s[j]){
        i++;
        j--;
        }
        else{
            return false;
        }
    }
    return true;

}
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check_palindrome(s,i,j))
                    cnt++;
            }
        }
        return cnt;
    }
};