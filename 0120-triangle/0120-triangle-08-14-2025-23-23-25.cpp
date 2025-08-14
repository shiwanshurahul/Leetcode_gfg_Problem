class Solution {
public:
int solve(vector<vector<int>> & triangle, int i, int j, int n, int m){
    if(i == n-1 )
        return triangle[i][j];    //include this in sum

    if(i> n-1 || i< 0 || j> n-1 || j<0)   
        return 1e9;

    int down_same_i = triangle[i][j] + solve(triangle, i+1, j, n, m);
    int down_adj = triangle[i][j] + solve(triangle, i+1, j+1, n, m);

    return min(down_same_i, down_adj);        
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        return solve(triangle, 0, 0, n, 1);
    }
};