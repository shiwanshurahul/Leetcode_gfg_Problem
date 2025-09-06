class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        //i b/w 0 to 60
        //num1 = num1 - (2^1 + num2)

        //num1` = num1 - (2^i` + num2)
        //num1`` = num1` - (2^i`` + num2)
        int t = 0;
        while(1){
            long long val = (long long)num1 - (long long) t *num2;

            if(val<0)
                return -1;

            if(__builtin_popcountll(val) <=t && t<=val)  //no of set bits
                return t;

        t++;    
        }
        return -1;
    }
};