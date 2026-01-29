class Solution {
public:
typedef long long ll;
    string decodeAtIndex(string s, int k) {
        //brute force -> mle
        //ha22, k=5 -> ha*2 = haha *2 = hahahaha -> o/p -> h
        //a23, k= 6 -> a*2 = aa*3 = aaaaaa -> o/p -> a
        //k = k%(size after decoding) 
        //if(k==0 && !isdigits(s[k-1]) )
        // return s[k-1]
        int n = s.length();
        ll siz = 0;
        for(auto it: s){  
            if(isdigit(it))  //number
                siz = siz*(it-'0');
            else
                siz += 1; 
        }

        for(int i=n-1;i>=0;i--){
            k = k%siz;
            if(k==0 && isalpha(s[i]))
                return string(1,s[i]);
            if(isalpha(s[i]))
                siz -=1;
            else //digit hai
                siz = siz/(s[i]-'0');        
        }
        return "";


    }
};