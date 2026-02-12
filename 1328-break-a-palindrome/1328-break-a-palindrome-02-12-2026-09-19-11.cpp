class Solution {
public:
    string breakPalindrome(string palindrome) {
        //givn string is palindrom
        //non palindrom banao lexiographicaly smalles
        //gredy
        //e.g."abccba" -> "aaccba" : replace krdeng 'b' ko 'a' se
        //= change the first non 'a' character to 'a'
        //e.g.2. "aaaa" -> "aaab" -> last 'a' ko 'b'
        //e.g.3 "aabaa" -> "aaaaa" -> still a palindrom
        //odd len ke middle letter ko change kiya fir v wo palindrom hi rhega
        //so, "aabab"

        //n/2 len tk me chnage krdo as baki half v same hai

        int n = palindrome.length();
        if(n==0 || n==1)
            return "";
        for(int i=0;i<n/2;i++){
            if(palindrome[i] !='a'){
                palindrome[i] = 'a';
                return palindrome;
            }    
        }
        //agar yaha hai toh sirf 'a' hai pehle "aabaa"
        palindrome[n-1] = 'b'; //second smallest and 
        return palindrome;
    }
};