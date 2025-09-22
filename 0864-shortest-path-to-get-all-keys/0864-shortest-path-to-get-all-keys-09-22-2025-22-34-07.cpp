class Solution {
public:
int n,m;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
bool isValid(int x,int y,vector<string>& grid){
    if(x>=0 && y>=0 && x<n && y<m)
        return true;
    return false;
}
    int shortestPathAllKeys(vector<string>& grid) {
        //can be 6 keys, sbka unique tala hoga
        //agar key ni hai kisi lock pe toh dusre adjacent pe jao and jb chabhi mile toh waps ao
        //3-d bfs i,j,key_status 
        n = grid.size();
        m = grid[0].size();
        int keys = 0; //pta kro kitne hai

        queue<pair<set<int>,pair<int,int>>>q;
        map<pair<set<int>,pair<int,int>>,int>vis;
        set<int>key;

        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j]=='@'){
                    q.push({key,{i,j}});
                    vis[{key,{i,j}}]=1;
               }
               if(grid[i][j]>='a' && grid[i][j]<='z')
                    keys++;
           }
       }
       
      
       int level=0;

       while(!q.empty()){
           int N=q.size();
           while(N--){
                key = q.front().first;
                int i = q.front().second.first;
                int j = q.front().second.second;
                q.pop(); 
                if(grid[i][j]>='a' && grid[i][j]<='z')
                    key.insert(grid[i][j]);
                if(key.size()==keys)
                    return level;
                for(int i_i=0;i_i<4;i_i++){
                    int nr = i+dr[i_i];
                    int nc = j+dc[i_i];
                    if(isValid(nr,nc,grid)==true){
                        if(grid[nr][nc]=='#')
                        continue;
                        if(grid[nr][nc]>='A' && grid[nr][nc]<='F' && key.find(tolower(grid[nr][nc]))==key.end())
                        continue;
                        if(vis[{key,{nr,nc}}]!=1){
                           vis[{key,{nr,nc}}]=1;
                            q.push({key,{nr,nc}});  
                        }
                    }
                }
            }
            level++; 
       }
        return -1;           
    }
};