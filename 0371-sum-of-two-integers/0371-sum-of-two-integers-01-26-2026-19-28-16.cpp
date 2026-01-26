class Solution {
public:
    int getSum(int a, int b) {
        //   a = 9 =  1 0 0 1
        //   b = 11 = 1 0 1 1
        //      a^b = 0 0 1 0 = 2
    //(a&b)<<1 = 1 0 0 1 0  //carry k lie
        //do this until 0 aaye  

    //  The XOR (^) operation acts like addition without carrying:

    // 0 + 0 = 0, 1 + 0 = 1, 0 + 1 = 1, 1 + 1 = 0 (since 1 ^ 1 = 0).
    // The AND (&) operation identifies where carries are needed:

    // Only when both bits are 1, you have a carry.
    // By shifting the carry left (<< 1), it aligns with the next bit to add.

    // Repeating this until there’s no carry left gives the full sum.

        while(b){
            int carry = (a & b) <<1; //left shift
            a = a ^ b;
            b = carry;
        }
        return a;
        
    }
};