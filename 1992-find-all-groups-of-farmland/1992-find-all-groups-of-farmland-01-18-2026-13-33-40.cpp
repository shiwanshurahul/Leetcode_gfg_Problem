class Solution {
public:
vector<vector<int>> dirn = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>> &land, int i,int j,int n,int m,int &r2,int &c2){
        if(i<0 || i>=n || j<0 || j>=m)
            return ;

        if(land[i][j] == 0)  //already vis ya not a farmland
            return; 

        land[i][j] = 0; //mark visited

        r2 = max(r2,i);
        c2 = max(c2,j);

        dfs(land,i+1,j,n,m,r2,c2);  //recursiv calls on nbr
        dfs(land,i-1,j,n,m,r2,c2);
        dfs(land,i,j+1,n,m,r2,c2);
        dfs(land,i,j-1,n,m,r2,c2);    
    }
    void bfs(vector<vector<int>>& land,int i,int j, int n,int m, int &r2, int &c2){
        queue<pair<int,int>> q;  //i,j
        q.push({i,j});

        while(!q.empty()){
            int i_ = q.front().first;
            int j_ = q.front().second;
            q.pop();

            r2 = max(r2,i_);
            c2 = max(r2,j_);

            for(auto it: dirn){
                int i__ = i_ + it[0];
                int j__ = j_ + it[1];

                if(i__ >=0 && i__<n && j__>=0 && j__<m && land[i__][j__] == 1 ){
                    land[i__][j__] = 0;   //mark visited
                    q.push({i__,j__});
                } 
            }
        }
        return;
    }   
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        //min val (i,j) and max val
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j] == 1){
                    int r1 = i;  //0 
                    int c1 = j;  //0
                    int r2 = -1;  //3 
                    int c2 = -1;  //3 
                    // dfs(land,i,j,n,m,r2,c2);
                    bfs(land,i,j,n,m,r2,c2);
                    ans.push_back({r1,c1,r2,c2});   
                }
            }
        }
        return ans;
    }
};