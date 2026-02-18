class Solution {
public:
int n = 0;
int m = 0;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int i, int j, vector<vector<char>>& board){
    if(i<0 || i>=n || j<0 || j>=m)
        return;

    if(board[i][j] !='X') //already vis or not a battsheship 
        return ;    

    board[i][j] = '.';  //mark visited

    for(auto it: dirn){  //dfs to all connected nbr
        int i_ = i + it[0];
        int j_ = j + it[1];

        dfs(i_,j_,board);
    }

}
    int countBattleships(vector<vector<char>>& board) {
        //no of 'x' return kro
        n = board.size();
        m = board[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] =='X'){
                    dfs(i,j,board);
                    cnt++;
                }        
            }
        }
        return cnt;
    }
};