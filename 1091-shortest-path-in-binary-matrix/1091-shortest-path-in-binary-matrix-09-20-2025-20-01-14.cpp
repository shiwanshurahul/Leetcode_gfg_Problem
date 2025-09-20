class Solution {
public:
int n,m;
// int solve(int i, int j, vector<vector<int>>& grid){
//     if(i<0 || j<0 || i>=n || j>=m )
//         return 1e9;

//     if(i==n-1 && j== m-1)
//         return 0;   //add 0 toh the path and return

//     if(grid[i][j] == 1)
//         return 1e9;

//     int up = 1 + solve(i-1,j,grid);
//     int down = 1 + solve(i+1,j,grid); 
//     int left = 1 + solve(i,j-1,grid);
//     int right = 1 + solve(i,j+1,grid);
//     // int diagonal = 1 + solve(i+1,j+1,grid);

//     return min({up, down, left, right});

// }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //0,0 to n-1,m-1
        //dp -> tle
        n = grid.size();
        cout<<n;
        m = grid[0].size();
          cout<<m;
        // return solve(0,0,grid);
        //min -> bfs

        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;

        queue<pair<int,int>> q;
        //0 wale push kro in q -> 8 direction
        q.push({0,0});
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            cout<<size<<endl;
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i== n-1 && j==m-1)
                    return level+1;

                // grid[i][j] = 1;  //mark visited 2 se v kr skte -> duplicacy 

                if(i+1<n && grid[i+1][j] !=1){ //not visited
                    q.push({i+1,j});
                    grid[i+1][j] = 1;
                }    

                if(i-1>=0 && grid[i-1][j] !=1){  //not visited
                    q.push({i-1,j});  
                    grid[i-1][j] = 1;
                }    

                if(j-1>=0 && grid[i][j-1] !=1){  //not visited
                    q.push({i,j-1});  
                    grid[i][j-1] = 1;  //mark visited
                }    

                if(j+1<m && grid[i][j+1] !=1){ 
                    q.push({i,j+1});  
                    grid[i][j+1] = 1;   //mark visited
                }    

                if(i+1<n && j+1<m && grid[i+1][j+1] !=1){ 
                    q.push({i+1,j+1}); 
                    grid[i+1][j+1] = 1;   //mark visited
                }    

                if(i-1>=0 && j-1>=0 && grid[i-1][j-1] !=1){ 
                    q.push({i-1,j-1}); 
                    grid[i-1][j-1] = 1;
                }    

                if(i+1<n && j-1>=0 && grid[i+1][j-1] !=1){ 
                    q.push({i+1,j-1}); 
                    grid[i+1][j-1] = 1;
                }    

                if(i-1>=0 && j+1<m && grid[i-1][j+1] !=1){ 
                    q.push({i-1,j+1});             
                    grid[i-1][j+1] = 1; 
                }    
            }
            level++;                        
        }
        return -1;
            //00 01 02
            //10 11 12
            //20 21 22
            //30 31 32
    }
};