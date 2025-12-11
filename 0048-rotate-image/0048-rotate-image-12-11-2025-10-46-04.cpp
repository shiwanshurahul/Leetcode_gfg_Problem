class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //  -   ->  |
        
        /* 1) transpose  ->   |1 4 7|
                              |2 5 8|
                              |3 6 9|
        rows will become columns & vice -versa
     
   2) reverse each row =  |7 4 1|
                          |2 5 8|
                          |3 6 9| =ans

     */
      
      int n = matrix.size();

      for(int i=0;i<n;i++){       //1
          for(int j=0;j<=i;j++){
              swap(matrix[i][j],matrix[j][i]);
          }
      }
      //2-> reverse every row
      for(int i=0;i<n;i++){
          reverse(matrix[i].begin(),matrix[i].end());
      }
//matrix me matrix[i] - 1d me row hi traverse hota
         
         
     }
};