class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m,1);
        vector<int> col(n,1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] ==0){
                    row[i] = 0;    //i=1 -> mark the idx
                    col[j] = 0;   //j=1
                }
            }
        }

    for(int i=0;i<m;i++){       // 0,1,2
        for(int j=0;j<n;j++){   // 0,1,2
            if(row[i]==0 || col[j]==0){ // (0,1), (1,0),(1,1), (1,2), (2,1)
                matrix[i][j] =0;
            }
        }
    }



    }
};