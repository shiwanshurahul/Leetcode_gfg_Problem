class Solution {
public:
typedef long long ll;
    string decodeAtIndex(string s, int k) {
        //brute forc -> mle
        //ha22, k=5 -> ha*2 = haha *2 = hahahaha -> o/p -> h
        //a23, k= 6 -> a*2 = aa*3 = aaaaaa -> o/p -> a
        //k = k%(size after decoding) 
        //if(k==0 && !isdigits(s[k-1]) )
        // return s[k-1]
        int n = s.length();  //leet2code3 = 10
        ll siz = 0;
        for(auto it: s){  
            if(isdigit(it))  //number 2
                siz = siz*(it-'0'); //4*2 = 8, 12*3 = 36
            else
                siz += 1; //1,2,3,4,9,10,11,12
        }

        for(int i=n-1;i>=0;i--){
            k = k%siz;   //10,10,0
            
            if(k==0 && isalpha(s[i]))
                return string(1,s[i]);
            if(isalpha(s[i]))
                siz -=1;            //11,10
            else //digit ha
                siz = siz/(s[i]-'0'); //12  
        }
        return "";


    }
};