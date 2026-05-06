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
        }//i=0 -> s(m00,m00) ; i=1 -> s(m10,m01), s(11,11) ;
        //i=2 -> s(20,02), s(21,12), s(22,22)

        //2-> reverse every row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
       }
        //matrix me matrix[i] - 1d me row hi traverse hota
         
         
    }
};