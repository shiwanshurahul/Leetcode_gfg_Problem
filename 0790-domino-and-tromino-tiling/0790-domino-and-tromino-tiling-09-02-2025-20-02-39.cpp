class Solution {
public:
int M = 1e9 +7;
int solve(int n, vector<int> &dp){
    
    if(n==1)
        return 1;

    if(n==2)
        return 2;

    if(n==3)
        return 5;

    if(dp[n] !=-1)
        return dp[n];

    return dp[n] = ( (2*solve(n-1, dp)) %M + solve(n-3, dp) %M) %M;            
}
    int numTilings(int n) {
     //domino and tromino ki size, width fix hai   
     //dono ek sath aa skte, ni v aa skte
     //board is 2*n e.g. 2*3, 2*4

     //n = 1 pe 1 domino no tromino -> 2*1 = f(1) = base case -> iska use kro and tile ko break krke socho 
     //n = 2 pe 2 domino no tromino ->  2*2 = f(2) = base case use = 2
     //n = 3 pe 3 domino and 2 tromino and sath me ni aa skte =5
     //n = 4 pe 2 tromino
    // koi v 2*n pe break krke socho
    //duplicate aa rha e.g n=2 se n=4 ka nikal rhe but n=3 ka v aa rha intermediate me
    //=avoid way jisse kisi interediate me pahunche
    //f(n) = f(n-1) + f(n-2) * f(1) + 2*f(n-3) + 2*f(n-4) + 2* f(n-5) +  2* .. 2*f(0)
    //eq2: f(n-1) = f(n-2) + f(n-3) + 2f(n-4) + 2f(n-5) + 2.f(0)
   
   //minus krdo = f(n) = 2*f(n-1) + f(n-3)
    vector<int> dp(n+1,-1);
    return solve(n, dp);

    }
};