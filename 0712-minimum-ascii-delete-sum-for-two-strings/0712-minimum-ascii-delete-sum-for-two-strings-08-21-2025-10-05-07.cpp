class Solution {
public:
int lcs(int i, int j, string &s1, string &s2){
    if(i>= s1.length() || j>= s2.length())
        return 0;   

    if(s1[i] == s2[j])   //1 len/match found
        return int(s1[i]) + lcs(i+1, j+1, s1, s2);  //len of lcsa ke jagah ascii ke basis pe
    else
        return max(lcs(i,j+1,s1,s2), lcs(i+1,j,s1,s2));    
        
}
    int minimumDeleteSum(string s1, string s2) {
        //lcs lelo
        int len = lcs(0,0,s1,s2);

        int char_sum=0;
        for(auto it: s1){
            char_sum+= it;
        }
        for(auto it: s2){
            char_sum += it;
        }
        return char_sum - 2*len;
    }
};