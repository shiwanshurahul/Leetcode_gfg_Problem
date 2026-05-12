class Solution {
public:
  int hammingWeight(uint32_t n) {
        int ans=0;
        while(n!=0){
        if(n&1)    //chk if the rightmot bit is a 1
            ans++;
        n = n/2; //n>>=1; 5, 
        }
        return ans;
}
};