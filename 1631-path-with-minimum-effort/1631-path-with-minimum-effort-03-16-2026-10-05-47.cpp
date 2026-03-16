class Solution {
public:
int n = 0;
int m = 0;
typedef pair<int, pair<int, int>> P;  //{diff, {x,y} }
vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 
bool is_valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m )
        return 0;
    return 1;    
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        n = heights.size();
        m = heights[0].size();
        //dijkstra in matrix -> {cost,i,j}
        // here, adj list ni banate 
        //single src to all the nodes
        //same as 1368,1631, Network dela

        //jo bol rha sirf uspe focs
        //return min diff jispe tm (n-1,m-1) pe ja skte
        // and maximu diff dhund rhe in minimised path
        
        //diff ke hisab se priority_q me store

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
  
        dist[0][0] = 0;   //src - src distanc is 0
        pq.push({0, {0,0}});
     
        while(!pq.empty()){
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(auto it: dirs){   //4 dir -> up, down, left, right
                int x_ = x + it[0];
                int y_ = y + it[1];
                if(is_valid(x_,y_) ){
                    int curr_diff = abs(heights[x_][y_] - heights[x][y]);
                    int max_diff = max(diff, curr_diff); //abtak k

                    if(dist[x_][y_] > max_diff){ //multiple bar chang hoga
                        dist[x_][y_] = max_diff;  //updat
                        pq.push({max_diff, {x_,y_}});
                    }
                }   
            }
        }
        // 0 1 1 
        // 2 5 1   -> dist
        // 2 2 2 
    return dist[n-1][m-1];

    }
};