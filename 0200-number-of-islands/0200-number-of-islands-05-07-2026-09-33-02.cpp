class Solution {
public:
int n,m;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int i, int j, vector<vector<char>>& grid){
    if(i<0 || j<0 || i>=n || j>=m)
        return;

    if(grid[i][j]!='1')  //alread visited ->grid[i][j]=='0' || grid[i][j]=='2'
        return;

    grid[i][j]='2';  //mark visited

    dfs(i+1,j,grid);    //recursiv call to possibl neighbors
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);

}
void bfs(int i, int j, vector<vector<char>>& grid){
    queue<pair<int,int>> q;  //{i,j}

    q.push({i,j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto it: dirn){
            int x_ = x + it[0];
            int y_ = y + it[1];
            if( x_>=0 && y_>=0 && x_<n && y_<m && grid[x_][y_] == '1' ){
                grid[x_][y_] = 0;   //mark visitd
                q.push({x_,y_});
                cout<<x_<<y_<<endl;
            }   
        }
    }
    
}
    int numIslands(vector<vector<char>>& grid) {
        //1 -> land

        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){   //land
                    // dfs(i,j,grid);
                    bfs(i,j,grid);
                    cnt++;  //sar connectd components visit krdo
                }
            }
        }
        return cnt;
    }
};