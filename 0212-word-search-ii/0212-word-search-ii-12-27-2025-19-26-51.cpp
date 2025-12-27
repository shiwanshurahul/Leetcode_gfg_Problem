class Solution {
public:
  vector<string> ans;
  int n;
  int m;

struct trieNode{
    trieNode * children[26];
    bool isEndOfWord;
    string endOfWord;
};

trieNode * create_Node(){
    trieNode * curr = new trieNode();
        curr->isEndOfWord = false;
        curr->endOfWord = " ";
        for(int i=0;i<26;i++){
            curr->children[i] = NULL;
        }
        return curr;
}

void insert_in_trie(string &word, trieNode * root){
    trieNode * curr = root;
    for(auto it: word){
        int ch_idx = it -'a';
        if(curr->children[ch_idx] ==NULL)
          curr->children[ch_idx] = create_Node();
        curr = curr->children[ch_idx];
    }
    curr->isEndOfWord = true;
    curr->endOfWord = word;
}

void find_words_dfs(vector<vector<char>>& board, int i, int j, trieNode * root){
    if(i<0 || i>=n || j<0 || j>=m)
        return;

    if(board[i][j] =='!' || root->children[board[i][j]-'a'] ==NULL)
        return;

      root= root->children[board[i][j] -'a'];  
      if(root->isEndOfWord == true){
         ans.push_back(root->endOfWord);
         root->isEndOfWord = false; 
        }
        
      char temp = board[i][j];   //mark visited root
      board[i][j] ='!';


      find_words_dfs(board, i-1, j, root);
      find_words_dfs(board, i+1, j, root); 
      find_words_dfs(board, i, j-1, root);
      find_words_dfs(board, i, j+1, root);      

      board[i][j] = temp;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //trie + dfs
         n = board.size(); 
         m = board[0].size();
        trieNode * root = create_Node();
        for(auto it: words){
            insert_in_trie(it, root);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ch_idx = board[i][j] - 'a';
                if(root->children[ch_idx] !=NULL)
                 find_words_dfs(board,i,j,root);
            }
        }
            return ans;
    }
};