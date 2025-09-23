class Solution {
public:

void dfs(int i,int j,vector<vector<char>>& grid){
    int n=grid.size();
    int m =grid[0].size();

    if(i<0 || j<0 || i>=n || j>=m)
        return;
        
    if(grid[i][j]=='0')  //already marked/visited
        return;      

    grid[i][j] ='0'; // mark visited

    dfs(i+1,j,grid);      //recursive call to possible neighbors
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
    
}
    int numIslands(vector<vector<char>>& grid) {
        //1 seperated kitni bar hai?
        //connected components in matrix-> "1" se call kro
        //dfs strategy-> mark visited and then recursive call to possible neighbors -> tree me v yahi hota e.g. solve(root->left) then solve(root->right); 
        // and inme generally void hota return type

        //2 types dfs que->ek no of provinces(graph) aur ek flood fill/no of island(matrix) jaisa-> same strategy
        //graph wale me dfs-> auto child krke recursive call and same strategy like already visited pe no
        //matrix wale me dfs->check ki i<= || i>=n || j<0 || j>=n || already marked and then call recursion to possible neighbors
           
           //2 bar call hota recursion in dfs   
             
            int cnt=0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]=='1'){  //land
                        dfs(i,j,grid);  //jitni bar call hoga wo count bcz ek bar me sare connected marked ho jaenge
                        cnt++;
                    }
                }
            }
            return cnt;
    }
};