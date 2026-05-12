class Solution {
public:
  int hammingWeight(uint32_t n) {
        int ans=0;
        // while(n!=0){ //1011, 101, 10->No, 1,0 
        // if(n&1)    //chk if the rightmot bit is a 1 -> 1011 & 0001
        //     ans++;
        // n = n/2; //n>>=1; 5, 2, 1 
        // }
        // return ans;

        //m2:     1011 & 1010 -> 1010
        while(n!=0){
            n = n & (n-1); //clear the rightmost bit
            ans++;
        }
        return ans;
    }
};