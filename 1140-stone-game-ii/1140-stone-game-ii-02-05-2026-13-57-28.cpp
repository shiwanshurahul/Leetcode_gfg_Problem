class Solution {
public:
int n = 0;
int dp[101][101][2];
int solve(int i, int person, int M, vector<int>&piles){
    if(i>=n)
        return 0; //add 0 to alice score and return score

    if(dp[i][M][person] !=-1)
        return dp[i][M][person];

    int ans = (person==1) ? -1 : 1e9;
    int stone = 0;
    for(int x=1;x<=min(2*M,n-i);x++){  //x=1,2 for M=1
        stone += piles[i+x-1];  //idx
        if(person)                        //i,person,M
            ans = max(ans, stone + solve(i+x, 0, max(M,x), piles));
        else
            ans = min(ans, solve(i+x, 1, max(M,x), piles));
    }
    return dp[i][M][person] = ans;    
}
    int stoneGameII(vector<int>& piles) {

        //min max optimal gam
        //apna bst -> Alice ka = max
        //expct wrst from bob = min
         
        //1 <=x<=2M = for loop for each x
        //here, x is piles jo wo utha skta
        //e.g. M=1 => x = 1,2 = max 2 piles utha skta
        //this can exceed n = min(2M,n-i) tk jao
        // q-> return the maximum number of stones Alice can get.
        // = bol rha alice ke rspc me hi likh
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,piles); //idx,Alice,M
        //Alice is person 1
    }//Alice agar i+x tk gaya toh Bob can go from (i+x)th idx and vce-ersa 
};