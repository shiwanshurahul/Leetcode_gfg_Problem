class Solution {
public:
int dp[501][501];
//express base cas in i,j
//explore all cases
//return max,min, sum, ..
int solve(int i, int j, vector<int>&piles){
    if(i>j)
        return 0;
    if(dp[i][j] !=-1)
        return dp[i][j];

    int ith_pick = piles[i] + solve(i+1,j, piles);
    int jth_pick = piles[j] + solve(i,j-1, piles);

    return dp[i][j] = max(ith_pick, jth_pick) ;   
}
    bool stoneGame(vector<int>& piles) {
        //min-max game
        //dp
        // 5,3,4,5
        // 0 1 2 3
        //If alice picks from odd idx toh bob ke pas even (0,2) 
        //If Alice picks from even idx toh bob ke pas odd (1,3)
        //Alic can hav all odd idx or even idx

        //either sum of all even idx is high or sum of all odd idx wale

        //Alice ke rspt me likh do 
        memset(dp,-1,sizeof(dp));
        int Alice_score = solve(0,piles.size()-1,piles); 
        int bob_score = 0;
        int sum = 0;
        for(auto it: piles){
            sum+= it;
        }
        bob_score = sum-Alice_score;
        return Alice_score > bob_score;
    }
};