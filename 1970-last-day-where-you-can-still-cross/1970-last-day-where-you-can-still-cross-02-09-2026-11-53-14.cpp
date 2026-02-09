class Solution {
public:
int n = 0;
int m = 0;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool dfs(int i,int j, vector<vector<int>>& grid){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;

    if(grid[i][j] != 0)  //water or already visited
        return false;  

    if(i==n-1)  //last row
        return true;

    grid[i][j] = 2; //mark visited    

    for(auto it: dirn){
        int i_ = i + it[0];
        int j_ = j + it[1];

        if(dfs(i_,j_,grid))
            return true;
    }
    return false;    
} 
bool bfs(int i,int j, vector<vector<int>>& grid){
    queue<pair<int,int>> q;   //{i,j}
    q.push({i,j});
    grid[i][j] = 1; //mark visited

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == n-1)
            return true;

        for(auto it: dirn){
            int i_ = x + it[0];
            int j_ = y + it[1];
            if(i_>=0 && i_<n && j_>=0 && j_<m && grid[i_][j_] ==0){
                q.push({i_,j_});
                grid[i_][j_] = 1;
            }
        }    
    }
    
    return false;    
} 

bool can_cross_is_possible(vector<vector<int>>& cells, int mid){
    vector<vector<int>> grid(n,vector<int>(m,0));

    for(int i=0;i<=mid;i++){  //pani bhardo 0 to mid
        int x = cells[i][0] - 1;  //1-based idx
        int y = cells[i][1] - 1;

        grid[x][y] = 1; //pani
    }

    for(int i=0;i<m;i++){ //0st row se hi star kro warna false
        if(grid[0][i] == 0 && bfs(0,i,grid))
            return true;  //can cross 
    }
    return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {        
        //upar ke kisi v idx se neeche ja skte
        //1-based idx ke hisab se pani bhar rha
        //= jbtak 0 th row me land hai ek v tbtak ja skte neeche (middle wale rows me v land ho)

        //brute force -> har din givn cell me pani bhar do and 
        //call bfs/dfs from 0th row -> agar last row me pahnch
        // rhe toh thik warna return last day jisme pahunche the
        // = tle = dfs+ b.s or bfs + b.s
        // = dfs on grid

        //b.s se sare givn cells me pani bharke dfs call ki no need
        //s,e,mid -> sirf s to mid tak sare cell me pani bhardo and
        // check if pahunch rhe last row me = ans = mid+1
        n = row;
        m = col;
        int s = 0;
        int e = cells.size()-1; //0 to mid wale cells me pani bhardo
        int ans = 0;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(can_cross_is_possible(cells,mid)){
                ans = mid+1; //1-based idx -> store ans
                s = mid+1; //right me jake aur chck krlo
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};