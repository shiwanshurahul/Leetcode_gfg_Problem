class Solution {
public:
int n = 0;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=n)
        return 0;
    return 1;    
}
bool is_possible(vector<vector<int>>& dist,int sf){
    // sf se min na ho ek v pura path from (0,0) to (n-1,n-1)
    // in dist grid
    queue<pair<int,int>> q; //{i,j}
    vector<vector<int>> vis(n,vector<int>(n,0));

    if(dist[0][0] < sf)
        return 0;

    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(i==n-1 && j== n-1)
            return true;

        for(auto &it: dirn){
            int i_ = i + it[0];
            int j_ = j + it[1];
            if(is_valid(i_,j_) && !vis[i_][j_]){
                if(dist[i_][j_] < sf)
                    continue;  //dusre path pe jao ye vlid path ni 

                q.push({i_,j_});
                vis[i_][j_] = 1;    
            }
        }    
    }
    return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //google
        //thief me jitna dur rho (safeness factor) utna acha
        // = safeness factor 1 to n tk me check krlo via b.s
        //konsa max safeness factr hai jisse tm 0,0 se n-1,n-1 ja skte
        //such that us path me wo min safeness facto ho

        //binary seach on grid multisrc dfs/bfs
        //similar to 01 matrix i.e instead of 
        //filling closest 1 for each 0, 1 se dist cal kr lo of all 0
        

        n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n,0));
        vector<vector<int>> vis(n, vector<int>(n,0));
        queue<pair<int,int>> q; //{i,j}

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});  //multisrc bfs
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto &it: dirn){
                int i_ = i + it[0];
                int j_ = j + it[1];
                if(is_valid(i_,j_) && !vis[i_][j_] ){ //unvisite
                    q.push({i_,j_});
                    dist[i_][j_] = 1 + dist[i][j];
                    vis[i_][j_] = 1;
                }
            }
        }
        
        //ab binary search on safeness facto
        int s = 0, e = 400; //n-1
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(is_possible(dist,mid)){ //is mid=sf is valid 
                ans = mid;  //store ans
                s = mid+1; //aur bada lena ka try
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};