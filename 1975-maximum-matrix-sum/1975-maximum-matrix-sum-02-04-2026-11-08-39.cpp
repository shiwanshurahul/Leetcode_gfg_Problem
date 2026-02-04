class Solution {
public:
typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        //maximize the sum of matri
        //odd no of -1 = tm -1 ko matrix ke min abs val pe le jao
        //even no of -1 = adjacent me le ja ke cancel out = all postive
        //e.g. |1 2 |  = |1 -2| = |-1 2|  -> odd
        //     |3 -5|    |3 5 |   |3 5|

        //e.g. |1 -2| =   |-1 -2| = 11 2|
        //     |-3 5|     |3  5 |   |3  5|

        int n = matrix.size();
        ll sum = 0;
        int min_val = 1e9;
        int negative_cnt = 0;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                min_val = min(abs(matrix[i][j]), abs(min_val));
                if(matrix[i][j] < 0) 
                    negative_cnt++;    
            }
        }
       
        if(negative_cnt%2 == 0)  //even no
            return sum;
        else
            return (sum - 2*(min_val));  //sum me added hai  
    }
};