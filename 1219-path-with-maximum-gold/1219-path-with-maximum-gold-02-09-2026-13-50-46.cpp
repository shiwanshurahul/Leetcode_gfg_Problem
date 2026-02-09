class Solution {
public:
int n = 0;
int m = 0;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return 0;
    return 1;    
}
int solve(int i,int j, vector<vector<int>>& grid){
    if( !is_valid(i,j))
        return 0;  //add 0 to sum and return

    if(grid[i][j] == 0)  //not allowed or already visited
        return 0;

    int temp = grid[i][j];   //taki bad me backtrack kre
    grid[i][j] = 0; //mark visited
    
    int ans = -1;

    for(auto &it: dirn){
        int i_ = i + it[0];
        int j_ = j + it[1];

        if(is_valid(i_,j_)){
            ans = max(ans, temp + solve(i_,j_,grid));
        } 
    }

    grid[i][j] = temp; //backtrack taki path v check kr ske

    return ans;    

}
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // use backtracki to try all paths and find the one with the 
        //maximum value.

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] !=0)  //quest me bola
                    ans = max(ans,solve(i,j,grid));
            }
        }
        return ans;
    }
};