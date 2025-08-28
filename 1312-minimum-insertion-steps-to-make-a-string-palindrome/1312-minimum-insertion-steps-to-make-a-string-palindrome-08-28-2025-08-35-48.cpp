class Solution {
public:
int lcs(string &s1, string &s2, int i,int j){
    if(i >= s1.length() || j>= s2.length())
        return 0;

    if(s1[i] == s2[j])
        return 1 +  lcs(s1,s2,i+1,j+1); //1 len add
    else       
        return max(lcs(s1,s2,i+1,j), lcs(s1,s2,i,j+1));
}
    int minInsertions(string s) {
        //mbadm   mbm
        //mdabm
        string s1 = s;
        reverse(s.begin(), s.end());
        
        if(s1 == s) //already a palindrome
            return 0;  

        int len_of_lcs = lcs(s1,s,0,0);
        return s1.length() - len_of_lcs;
    }
};