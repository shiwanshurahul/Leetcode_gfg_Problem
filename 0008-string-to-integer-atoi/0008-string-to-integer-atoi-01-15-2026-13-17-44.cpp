class Solution {
public:
typedef long long ll;
    int myAtoi(string s) {
        //"   -042"  -> 042
        //ek v alpha mile toh retrn ans 
        int i=0;
        int sign = +1;
        while(i<s.length()){
            if(s[i]!=' ')
                break;
            i++;    
        }  //removed whitespace
        s = s.substr(i) ; //-042
        i=0; //is s pe iterate
        ll ans=0;
        if(s[0]== '-'){
            sign = sign*-1;   
            i++;
        }
        else if(s[0]=='+'){
            i++;
        }    
        while(i<s.length()){  //042
            if( !isdigit(s[i]) )
                return sign*(int)ans;
            ans = (ans*10) + (s[i]-'0'); //convert to digit    
            i++;
            if(sign * ans>= INT_MAX)
                return INT_MAX;
            if(sign * ans <= INT_MIN)
                return INT_MIN;    
        }
        return sign *(int)ans;
    }  //'9' => '9'-'0' = 9
};