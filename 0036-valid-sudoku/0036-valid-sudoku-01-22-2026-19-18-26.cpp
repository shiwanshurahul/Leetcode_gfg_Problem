class Solution {
public:
/*
bool traversal(vector<vector<char>>& board,int sr,int er,int sc,int ec){
 unordered_set<char> st;
 for(int i=sr;i<=er;i++){
     for(int j=sc;j<=ec;j++){
         if(board[i][j]=='.') continue;
         if(st.find(board[i][j])!=st.end())
         return false;
         st.insert(board[i][j]);
     }
 }
 return true;
}*/
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>st;
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')
                continue;
             // string(1,board[i][j])=value in string form
             // +"row"+ ni daloge toh same value col me v aa skti.eg.50 
            string row =string(1,board[i][j])+ "row"+ to_string(i);//5row0,3row0
            string col =string(1,board[i][j]) + "col" + to_string(j);//5col0
            string box =string(1,board[i][j])+"box" +to_string(i/3)+to_string(j/3);
            if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end())
                return false;

           st.insert(row);
           st.insert(col);
           st.insert(box);
            }
        }
        return 1;
  //ATQ, "." = ignore
     
      //sare row me 1-9 with no duplicate
      //sare column me 1-9 with no duplicate
     //sare 3*3 ke box me 1-9 with no duplicate-> 9 boxes in total
   //i.e o-2, 3-5,6-8
     // = teeno me se ek v jagah duplicate = invalid  

     
  //   brute force -> 3 for loops for these 3 
                                          
     // 1. validate rows:
    //  for(int row =0;row<9;row++){
    //      unordered_set<char> st; //unique 1-9 only allowed
    //      // each row me check hoega 
    //      for(int col =0;col<9;col++){
    //      if(board[row][col]=='.') continue;
    //      if(st.find(board[row][col])!=st.end()) return false;
    //      st.insert((board[row][col]));
    //      }
    //      } 
                
    //      //2. validate col
    //      for(int col =0;col<9;col++){
    //          unordered_set<char> st;   //each col me check
    //          for(int row=0;row<9;row++){
    //          if(board[row][col]=='.') continue;  board[0][0],board[1][0],board[2][0]
    //      if(st.find(board[row][col])!= st.end()) return false;
    //      else
    //      st.insert(board[row][col]);
    //          }
    //      }*/
         //3. validate each 3*3 submatrices
             /*   0 1 2
                 0| | |
                 1| | |
                 2| | |  
           starting row and ending row ka khel
           starting row+2 =ending row
           starting col+2 = ending col
           
           for(int sr=0;sr<9;sr+=3){ //+=3 bcz sare 3*3 ka thore chahiye just 0-2 , 3-5,6-8 wala
               int er =sr+2;
               for( int sc =0;sc<9;sc+=3){
                   int ec =sc+2;
                   //traversal call
                   if(!traversal(board,sr,er,sc,ec))
                   return false;
               }
           }
           return true;                 

      return 1;*/
      }
       
};