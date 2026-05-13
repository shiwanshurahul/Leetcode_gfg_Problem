class Solution {
public:
bool isequal(vector<int> v1,vector<int> v2){
    for(int i=0;i<26;i++){
        if(v1[i]!=v2[i])
        return false;
    }
    return 1;
}
    bool checkInclusion(string s1, string s2) {

        //fixed size slidin windo -> window len = s1.size() rkh
        if(s1.size()>s2.size())
            return 0;

        int i=0,j=0;
        vector<int> v1(26,0); 
        vector<int> v2(26,0);

        for(char ch : s1){  //stor all char of s1 in v1
            v1[ch- 'a']++;
        }
        while(j<s2.size()){
            v2[s2[j] - 'a']++;
            if(j-i+1 == s1.size()){
                if(isequal(v1,v2)){
                    return 1;
                }
                else{   //size sam ha but v1 and v2 are not equal
                  v2[s2[i] - 'a']--;  //window len same rhne do 
                  i++;j++;
                }
            }
            else if(j-i+1<s1.size()){
                j++;
            }
        }
        return 0;
    }
};