class Solution {
public:
int n = 0;
int m = 0;
typedef pair<int, pair<int,int>> p;
vector<vector<int>> dirn = {{-1,0},{1,0},{0,-1},{0,1}};
bool is_valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return 0;
    return 1;    
}
    int swimInWater(vector<vector<int>>& grid) {
        //djiktra on grid -> {cost,i,j} ->
        // here, adj list ni banate 
        //single src to all the nodes
        //same as 1368,1631, Network dela
        //water level same ho tbhi ja skte adjacen pe
        //'t' har sec badh rha toh jaise hi curr + t >= adjacen toh adjacent pe jao
        //return min t jispe tm (n-1,m-1) pe ja skte
        //maximu time dhund rhe in minimised path
        //e.g. 0 + t=1 = 1;
        //     1 + t=2 = 2;
        //     2 + t=3 = 3;
        //     3 + t=4 = 4
        //     4 + t=5 = 5
        //     5 + t=6

        n = grid.size();
        m = grid[0].size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[0][0] = grid[0][0]; //src to src distanc is 0
        pq.push({grid[0][0], {0,0,}}); //{val,{x,y}}

        while(!pq.empty()){
            int elevate = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto it: dirn){
                int x_ = x + it[0];
                int y_ = y + it[1];

                if(is_valid(x_,y_)){
                    if(dist[x_][y_] > max(elevate, grid[x_][y_] )){
                        dist[x_][y_] = max(elevate, grid[x_][y_]);
                        pq.push({ dist[x_][y_], {x_,y_}} );
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};