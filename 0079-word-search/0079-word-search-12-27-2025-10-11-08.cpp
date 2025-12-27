class Solution {
public:
//backtracking = dfs
int n,m;
bool dfs(int i,int j,vector<vector<char>>& board,string word,int len_of_word_found){
       if(len_of_word_found==word.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        if(board[i][j]!= word[len_of_word_found] || board[i][j]=='!')
            return false; //already vis    


        char temp =board[i][j]; //asked in ques
        board[i][j] ='!';      //mark it visited
 
        bool ans = dfs(i-1, j, board, word, len_of_word_found+1 ) ||
                   dfs(i+1, j, board, word, len_of_word_found+1 ) ||
                   dfs(i, j-1, board, word, len_of_word_found+1 ) ||
                   dfs(i, j+1, board, word, len_of_word_found+1 );

        board[i][j] = temp;       //mark it unvisited
        return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if( dfs(i,j,board,word,0) )
                        return true;
                }
            }
        }
        return false;
    }
};