class Solution {
public:
bool dfs(int i, int j, vector<vector<int>>& grid){
    if(i<0 || i>= grid.size() || j<0 || j>=grid[i].size())   //out of bound = not closed
        return false;

    if(grid[i][j] == 1)  //water mila ek dirn me
        return true;

    grid[i][j] = 1;  //mark visited -> 2 kuch v fir upar grid[i][j] != 0 me return true

     //recursive call to possible neighbors
    bool next_row = dfs(i+1,j,grid);
    bool prev_row = dfs(i-1,j,grid);
    bool next_col = dfs(i,j+1,grid);
    bool prev_col = dfs(i,j-1,grid);

    return next_row && prev_row && next_col && prev_col;
    //charo dirn se mile toh hi cnt++
}
    int closedIsland(vector<vector<int>>& grid) {
        //dfs me do bar recursive call hote 
        // 1-> water, 0 -> land
        //closed -> charo taraf 1(water) ho of 0
        //boundary -> not closed

        //jo v 0th row, n-1 row, 0th col, m-1 col me 0 wale component hai unko ignore kro -> no of enclaves 
        //waise v kr skte ya ek dfs likh lo jo true false return kre 

    
        int cnt =0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 0){   // = land = iske charo taraf pani search
                    if(dfs(i,j,grid))
                        cnt++;       
                }
            } 
        }
        return cnt;
    }
};