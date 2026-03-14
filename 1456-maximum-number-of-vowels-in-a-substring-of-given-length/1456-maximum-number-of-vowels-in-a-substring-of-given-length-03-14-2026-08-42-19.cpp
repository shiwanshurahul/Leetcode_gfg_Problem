class Solution {
public:
bool isvowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    return 1;
    return 0;
}
    int maxVowels(string s, int k) {
        //fixed le slidin window -> ke pe pahunch ke const rkho
        int i=0,j=0;
        int cnt=0;
        int maxi =0;
        while(j<s.length()){
            if(j-i+1<k){
                if(isvowel(s[j]))
                    cnt++;
                j++;
            }
            else if(j-i+1==k){
                if(isvowel(s[j]))
                    cnt++;
                maxi = max(cnt,maxi);   //cal ans
                if(isvowel(s[i]))       //remove cal for i
                    cnt--;  
                i++;                    //slide the window
                j++;
            }
        }
        return maxi;
    }
};