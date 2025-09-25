class Solution {
public:
int n,m;
vector<vector<int>> ans;
void dfs(int i, int j, int node_i, int node_j, vector<vector<int>>&vis, vector<vector<int>>& heights){
    if(i<0 || j<0 || i>=n|| j>=m || vis[i][j]==1)    //already marked
        return;

    if( (node_i>=0 && node_j>=0 && heights[node_i][node_j] > heights[i][j]) )
        return;   

    vis[i][j] = 1;  //mark vis

    dfs(i+1,j,i,j,vis,heights);   //possible recursive calls to neighbors
    dfs(i-1,j,i,j,vis,heights);
    dfs(i,j+1,i,j,vis,heights);
    dfs(i,j-1,i,j,vis,heights);    
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //return a list of cells jahan se pani atlantic & pacific dono m jaega
        //top right and bottom right se hme dono me jaega
        //har cell se dekho pahunch skte ki ni kisi v ocean pe such that adjacent cell is <= val
        // = dono ocean ka apna list hoga last m return common
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> vis_pacific(n, vector<int>(m,0));
        vector<vector<int>> vis_atlantic(n,vector<int>(m,0));

      for(int i=0;i<n;i++){
            dfs(i, 0, -1, -1, vis_pacific, heights);   //first col
            dfs(i, m-1, -1, -1, vis_atlantic, heights); //last col
        }

        for(int j=0;j<m; j++) {
            dfs(0, j, -1, -1, vis_pacific, heights);  //first row 
            dfs(n-1, j, -1, -1, vis_atlantic, heights);  //last row
        }

        for(int i=0;i<n; i++){
            for(int j =0;j<m; j++){  //dono me pahunch skta
                if(vis_pacific[i][j]==1 && vis_atlantic[i][j]==1) 
                    ans.push_back({i, j});   
            }
        }
        return ans;
    }
};