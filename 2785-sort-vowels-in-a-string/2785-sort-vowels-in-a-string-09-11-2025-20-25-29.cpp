class Solution {
public:
bool isVowel(char ch){
    if(ch == 'A' || ch=='E' || ch=='I' || ch=='O' ||ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    return true;
    return false;
}
    string sortVowels(string s) {
        //A-Z : 65- 90
        //a-z : 97-122
        //Capital ka ascii chota hai
        //alag se vowel leke sort krdo
        string temp="";
        for(int i=0;i< s.length();i++){
            if(isVowel(s[i])){
                temp+=s[i];
                s[i] = '!';
            }
        }
        
        sort(temp.begin(), temp.end());  //vowel str

        int j=0; 
        for(int i=0;i< s.length();i++){
            if(s[i] =='!'){
             s[i] = temp[j++];
            }
        }
        return s;
    }
};