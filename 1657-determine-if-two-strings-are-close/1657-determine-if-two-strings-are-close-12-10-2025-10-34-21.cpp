class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //same char ho dono me
        // freq v match ho taki transform kr ske
        //e.g. cabbba ; abbccc are close bcz same char with matching freq same

        vector<int> w1(26,0);
        vector<int> w2(26,0);
        if(word1.length() != word2.length())
            return false;

        for(int i=0;i<word1.length();i++){
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(w1[i]==0 && w2[i]!=0 ) //char w1 me hai but w2 me ni
                return false;
            else if(w1[i]!=0 && w2[i] ==0)
                return false;    
        }

        //2nd -> freq match
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        return w1== w2;

    }
};