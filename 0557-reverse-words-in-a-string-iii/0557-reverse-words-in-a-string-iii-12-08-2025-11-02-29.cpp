class Solution {
public:
    string reverseWords(string s) {
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
            //    int k =i;
                reverse(s.begin()+k,s.begin()+i);
                k=i+1;
            }
        }
        reverse(s.begin()+k,s.end());
        return s;
    }
};
