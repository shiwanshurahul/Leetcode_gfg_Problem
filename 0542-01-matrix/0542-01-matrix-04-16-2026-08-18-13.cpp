class Solution {
public:
int n,m;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return 0;
    return 1;    
}
int dfs(int i, int j, vector<vector<int>>& mat, int cnt){
    if(i<0 || i>=n || j<0 || j>=m)
        return 1e9;
    if(mat[i][j]==0)
        return cnt;

    if(cnt> n*m)
        return 1e9;

    int up = dfs(i+1,j,mat,cnt+1);
    int down =dfs(i-1,j,mat,cnt+1);
    int left = dfs(i,j+1,mat,cnt+1);
    int right = dfs(i,j-1,mat,cnt+1);
    return min(min(up,down), min(left,right));    
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //nearest = bfs
        n = mat.size();  //dfs se min ki guarantee ni and tle aaega
        m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        //har 1 pe jake bfs mardo ->tle

        queue<pair<int,int>> q;  //i, j -> multisrc bfs
        //store coordinates of all 0's -> call bfs from thes
        //in 0 wale coordinates se har jagah pahunc
        // = distance of the nearest 0 for each cell
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }     
            }
        }

        int level = 0;   //traditional bfs on matrix -> idhar no need
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            //explor the nbrs of this levl
            for(auto it: dirn){
                int i_ = i + it[0];
                int j_ = j + it[1];
                if(is_valid(i_,j_) && ans[i_][j_] == -1){  //unvisited
                    ans[i_][j_] = ans[i][j] + 1;  //mark visited
                    q.push({i_,j_});
                }
            }
        }
        return ans;

    }
};