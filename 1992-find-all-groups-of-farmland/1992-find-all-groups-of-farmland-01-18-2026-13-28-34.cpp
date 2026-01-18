class Solution {
public:
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
                    dfs(land,i,j,n,m,r2,c2);
                    ans.push_back({r1,c1,r2,c2});   
                }
            }
        }
        return ans;
    }
};