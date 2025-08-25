class Solution {
public:
int n,m;
void dfs(vector<vector<char>> &board, int i, int j){
    if(i>= n || i<0 || j>= m || j<0)
        return;

    if(board[i][j] != 'O' )
        return;

    board[i][j] = '!';  //mark visited
    
    dfs(board,i,j+1);  //dfs to possible neighbors
    dfs(board,i,j-1);
    dfs(board,i+1,j);
    dfs(board,i-1,j);

}
    void solve(vector<vector<char>>& board) {
        //charo taraf x hai toh replace 0 with x
        //boundary se touch ni hai toh O  ko 1 me change
        //agar boundary me hai toh fir O rhega O ka sara connected components jo O hai
        n = board.size();
        m = board[0].size(); 

        //first row, first col, last row,last col me check

        //0th row:
        for(int i=0;i<m;i++){
            if(board[0][i] =='O')
                dfs(board,0,i);
        }    

        //last row
        for(int i=0;i<m;i++){
            if(board[n-1][i] =='O'){
                dfs(board,n-1,i);
            }
        }    

        //oth col
        for(int i=0;i<n;i++){
            if(board[i][0] =='O')
                dfs(board,i,0);
        }    

        // //last col
        for(int i=0;i<n;i++){
            if(board[i][m-1] == 'O')
                dfs(board,i,m-1);
        }

         //baki ko convert to X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';  
            }
        }

        //! wale ko change to 0
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '!')
                    board[i][j] = 'O';
            }
        }

       
        
    }
};