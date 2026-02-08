class Solution {
public:
typedef pair<int, pair<int, int>> P;  //<dif, pair<x, y>>
vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        //dijkstra in matrix -> {cost,i,j}
        //src to dest with shortest weight
        //diff ke hisab se priority_q me store

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
  
      dist[0][0] = 0;   //src - src distanc is 0
      pq.push({0, {0,0}});
     
     while(!pq.empty()){
        int dis = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(auto it: dirs){   //4 dir -> up, down, left, right
            int x_ = x + it[0];
            int y_ = y + it[1];
            if(x_>=0 && x_<= n-1 && y_>=0 && y_<=m-1 ){
                int diff = abs(heights[x_][y_] - heights[x][y]);
                int max_diff = max(dis, diff);

                if(dist[x_][y_] > max_diff){ 
                    dist[x_][y_] = max_diff;
                    pq.push({max_diff, {x_,y_}});
                }
            }
        }
     }
     return dist[n-1][m-1];

    }
};