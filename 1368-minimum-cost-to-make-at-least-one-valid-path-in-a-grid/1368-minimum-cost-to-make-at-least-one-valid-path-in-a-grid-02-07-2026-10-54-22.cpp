class Solution {
public:
int n = 0;
int m = 0;                  //R     L      D     U   
vector<vector<int>> dirn = {{0,1},{0,-1},{1,0},{-1,0}};
typedef vector<int> v; //<int, pair<int,int>> v le skte -> it.second.first 
bool is_valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return 0;
    return 1;     
}
int check_cost(int temp, int i){ //same dirn me ja rhe toh 0 warna return 1
    if( (temp == 1 && i!=0) || (temp==2 && i!=1) || (temp==3 && i!=2)
      || (temp==4 && i!=3) )
        return 1; //add 1 to cost

    return 0; //no cost needed as udhar hi ja rhe     
}

int solve(int i,int j, vector<vector<int>>&grid, int cost){
    if(i==n-1 && j==m-1)
        return cost; //add 0 to cost

    int temp = grid[i][j];  //to bactrack
    grid[i][j] = -1;        //mark visited    
    
    int ans = 1e9;
    for(auto dir_idx=0;dir_idx<4;dir_idx++){  //dirn pe iterte
        int i_ = i + dirn[dir_idx][0];
        int j_ = j + dirn[dir_idx][1];
       
        if(is_valid(i_,j_) && grid[i_][j_] != -1){  //not visited
            int next_cost = cost + check_cost(temp,dir_idx); //curr + kidhar ja rhe
            ans = min(ans, solve(i_,j_,grid,next_cost));
        }
    }

    grid[i][j] = temp; //backtrack taki dusre path wale try kre
    return ans;

}
    int minCost(vector<vector<int>>& grid) {
       
        //explore all paths and backtrack to get min cost
        n = grid.size();
        m = grid[0].size();
        // return solve(0,0,grid,0); 
        //->tle


        // m2: 
        // djikstr on grid ->{cost,i,j} store in pq
        //2-d dist arr -> idhar visited arr ki no need
        //directed graph hai as dir hai har point pe ki kidhar jana
        // min cost puch rha
        //adj list ki no need
        // idhar vector<pair<int,int>> isliye hota bcz there can be 
        //multiple adj nodes
        //dijkstra -> nbr ke via min dist ki kosis

        //dijkstra is single src to each node ka min duration
        //Note: dist me store hai src se har node jane ka distance 
        //e.g. src=0: 0-0 jane ka dist, 0-1 jane ka dist, 0-2 jane ka dist

        priority_queue<v, vector<v>, greater<v>> pq; 
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        pq.push({0,0,0}); //{cost,i,j}
        dist[0][0] = 0;   //dist b/w src to src is 0

        while(!pq.empty()){
            auto node = pq.top();  //vector hai
            pq.pop();
            int cost = node[0];
            int i = node[1];
            int j = node[2];

            for(auto dir_idx=0;dir_idx<4;dir_idx++){
                int i_ = i + dirn[dir_idx][0];
                int j_ = j + dirn[dir_idx][1];
        \
                if(is_valid(i_,j_) ){
                    int new_cost = cost + check_cost(grid[i][j],dir_idx);
                    if(new_cost < dist[i_][j_]){
                        dist[i_][j_] = new_cost; //1,,2 < 1e9
                        pq.push({new_cost,i_,j_});
                    }
                }
            }
        }
        return dist[n-1][m-1]; 
        
    }
};