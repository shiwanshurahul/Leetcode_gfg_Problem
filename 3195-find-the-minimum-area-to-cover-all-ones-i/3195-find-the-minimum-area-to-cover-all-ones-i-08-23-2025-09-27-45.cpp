class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //l = col1-col2+1
        //b = row1-row2+1
        //row-wise and col wise expand kro to include all 1
        //maxCol -> right most col jisme 1 hai
        //minCol -> left most col jisme 1 hai
        //maxCol- minCol+1 = length

        //minRow -> pehla ka row jisme 1 hai
        //maxRow -> last row jisme 1 hai
        int n = grid.size();
        int m = grid[0].size();

        int maxCol = -1, minCol = m;
        int maxRow = -1, minRow = n; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1){
                    maxCol = max(maxCol, j);
                    minCol = min(minCol, j);
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                }
            }
        }
    
        return (maxCol-minCol +1) * (maxRow - minRow +1);
    }
};