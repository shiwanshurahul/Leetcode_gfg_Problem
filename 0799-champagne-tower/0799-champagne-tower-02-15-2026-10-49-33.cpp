class Solution {
public:
//find base case in terms of i and j
//explore all cases as per problm
//return max,min,sum, ..
double dp[101][101];
double solve(int row, int col, int poured){
    if(row<0 || col <0)
        return 0.0;

    if(row == 0 && col==0)   //0th row me 1 toh glass me girega         
        return (poured-1.0)/2;   // baki left and right me gireg equaly 
    
    if(col>row)   //invalid idx
        return 0.0;

    if(dp[row][col] != -1.0)
        return dp[row][col];

    double left_up = solve(row-1,col-1,poured);
    double right_up = solve(row-1,col,poured);

    if(left_up < 0)
        left_up = 0;

    if(right_up < 0)
        right_up = 0;    

    return dp[row][col] = left_up + right_up ;  //kisi v glass pe 
                                                //in dono se a skta
}
double solve1(int row, int col, int poured){
    if(row<0 || col <0)
        return 0.0;

    if(row == 0 && col==0)   //0th row me 1 toh glass me girega         
        return poured;   // baki left and right me gireg equaly 
    
    if(col>row)   //invalid idx
        return 0.0;

    if(dp[row][col] != -1)
        return dp[row][col];

    double left_up = (solve1(row-1,col-1,poured)- 1.0) /2.0;
    double right_up = (solve1(row-1,col,poured) - 1.0) /2.0;

    if(left_up < 0)
        left_up = 0.0;

    if(right_up < 0)
        right_up = 0.0;    

    return dp[row][col] = left_up + right_up;  //kisi v glass pe 
                                                //in dono se a skta
}
    double champagneTower(int poured, int query_row, int query_glass) {
        //1st row -> 1, 2nd row -> 2, 3rd row -> 3 , ..
        //similar to pascal's triangle
        // Champagne ek pyramid pattern me flow karti hai.

        //pehle 1.0 bharega curr glss me fir remaining ka half girega 
        //left and right me equally

        // Agar glass full ho jata hai, toh extra champagne neeche ke 2 glasses me equally divide hoti hai.

        // Kisi bhi glass (i, j) ka amount depend karta hai:
        // left parent (i-1, j-1) 
        // right parent (i-1, j)

        //kisi v row me no of col <=row = pascl
        // memset(dp,-1.0,sizeof(dp));  -> only for int
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1.0;
            }
        }
        //solve and solve1 are same
        return min(1.0, solve1(query_row,query_glass, poured));
    } 
};