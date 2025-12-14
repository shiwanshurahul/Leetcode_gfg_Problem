class Solution {
public:
typedef pair<int,int> p;  //up,   down,   left,  right
vector<vector<int>> dirn {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        //multisrc bfs
        int n = grid.size();
        int m = grid[0].size();
        queue<p> q;
        int cnt_fresh_orng = 0;
        for(int i=0;i<n;i++){   
            for(int j=0;j<m;j++){                                                                                                                                                                                                                               
                if(grid[i][j]==2)
                    q.push({i,j}); //idx store
                else if(grid[i][j]==1)
                    cnt_fresh_orng++;  //taki last me check kr ske ki
            }                          // sare orange rotten ho jaye
        }
        if(cnt_fresh_orng == 0)
            return 0;

        int lvl = 0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto it: dirn){
                    int new_i = i + it[0];
                    int new_j = j + it[1];
                    if(new_i>=0 && new_i <n && new_j>= 0 && new_j <m && grid[new_i][new_j] == 1){
                        grid[new_i][new_j] = 2;  //mark visited
                        q.push({new_i, new_j});   //push to queue
                        cnt_fresh_orng--;
                    }
                }    
            }
            lvl++;
        }
        return cnt_fresh_orng == 0 ? lvl-1 : -1;
    }
};