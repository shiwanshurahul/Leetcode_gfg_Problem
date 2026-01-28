class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r= 0,c=matrix[0].size()-1;   //r=0,c=3
        while(r<matrix.size() && c<matrix[0].size()){
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]>target)
                c--;   //prev col same row
            else if(matrix[r][c]<target)
                r++;   //next row
        }
        return 0;
    }
};