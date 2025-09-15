class Solution {
public:
int cnt = 0;
void dfs(int i, int j, vector<vector<char>>& maze){
    if(i<0 || j<0 || i>= maze.size() || j>= maze.size() || maze[i][j]=='+')
        return;
    if(i==0 ||j==0 && maze[i][j]=='.')
        cnt++;    

    maze[i][j]='!';   //mark visited

}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //shortest -> bfs
        // dfs(entrance[0], entrance[1], maze);

        //boundary -> i=0 || j=0 || i==n-1 || j=m-1
        //i,j ! entrance[0], entrance[j]
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>> q;  //coordinates dalo
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; //mark visited

        int ans=0;
        while(!q.empty()){
            int N = q.size();
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();  //check this is a boundary or what
                if( (i==0 || j==0 || i==n-1 || j==m-1) && (i!=entrance[0] || j!= entrance[1]) ) 
                    return ans;

                //explore the neighbors 
                if(i-1>=0  && maze[i-1][j] !='+'){   
                    q.push({i-1,j});
                    maze[i-1][j] ='+';
                }
                if(i+1<n && maze[i+1][j] !='+'){
                    q.push({i+1,j});
                    maze[i+1][j] ='+';
                }
                if(j-1>=0 && maze[i][j-1] !='+' ){
                    q.push({i,j-1});
                    maze[i][j-1] = '+';
                }
                if(j+1<m && maze[i][j+1] !='+' ){
                    q.push({i,j+1});
                    maze[i][j+1] = '+';
                }
                
            }
            ans++;
        }

        return -1;
    }
};