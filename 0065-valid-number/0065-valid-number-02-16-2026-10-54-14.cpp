class Solution {
public:
    bool isNumber(string s) {
        //2 sign ni hoenge valid no me i.e -+3 or -- 3 -> Not valid
        // 2 dots -> Not valid
        // 2 e/E / start with e/E / end with e/E -> Not valid

        //count of sign > 2 = not valid e.g. +6e-1" is valid
        //If dusri bar a v rha sign and usse pehl e/E ni hai toh not val 

        //last idx pe dot ya e ya E -> invalid

        //so, chek and flags dalo

        //sar invalid cas liko

        int n = s.length(); 
        int digit_seen = 0;  //digit dekha hai -> digit kitne v bar a skta
        int e_seen = 0;
        int dot_seen = 0;
        int count_sign = 0; //2 tak max 

        for(int i=0;i<n;i++){
            char ch = s[i];
            
            //digit hai:
            if(isdigit(ch)) {
                digit_seen = 1;
            }     
            
            //+ or - sign:
            else if(ch=='+' || ch=='-'){
                if(count_sign == 2) //alredy 2 hai, avi is 3rd
                    return false;
                else if(i>0 && (s[i-1] !='e' && s[i-1] !='E'))
                    return false;  //middle me a rha sign
                else if(i == n-1)  //last idx
                    return false;
                else    
                    count_sign++;       
            }
            
            // dot:
            else if(ch=='.'){
                if(e_seen || dot_seen)
                    return false;
                else if(i == n-1 && !digit_seen)
                    return false;
                else
                    dot_seen = 1;    
            }

            // e or E 
            else if(ch=='e' || ch=='E'){
                if(e_seen || !digit_seen || i == n-1)
                    return false;
                else
                    e_seen = 1;    
            }
            else{  //any other char than these 4 case
                return false;
            }
        }
        return true;

    }
};