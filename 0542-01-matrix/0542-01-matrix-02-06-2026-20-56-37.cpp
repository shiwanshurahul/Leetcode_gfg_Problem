class Solution {
public:
int n,m;
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
        n =mat.size();  //dfs se min ki guarantee ni and tle aaega
        m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        //har 1 pe jake bfs mardo ->tle

        queue<pair<int,int>> q;  //i, j
        //store coordinates of all 0's -> call bfs from these
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }     
            }
        }

        int level = 0;    //traditional bfs on matrix -> idhar no need
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            //explore the nbrs of this level
            if(i-1 >= 0 && ans[i-1][j] ==-1){  //-1 ho tbhi
                ans[i-1][j] = ans[i][j] +1; 
                q.push({i-1, j});     //idhar v mark visited kr skte 
            }
            if(i+1 < n && ans[i+1][j] ==-1){
                ans[i+1][j] = ans[i][j] +1; 
                q.push({i+1, j});     //idhar v mark visited kr skte 
            }
            if(j-1 >= 0 && ans[i][j-1] ==-1){
                ans[i][j-1] = ans[i][j] +1; 
                q.push({i, j-1});
            }
            
            if(j+1 < m && ans[i][j+1] ==-1){
                ans[i][j+1] = ans[i][j] +1; 
                q.push({i, j+1});
            }
        }
        
        return ans;

    }
};