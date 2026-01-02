class Solution {
public:
typedef pair<int,int> p;
vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //1 water = ye 0 hoga  and yahi se bfs chalu
        //multi src bfs
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1)); // -1 = unvisited
        queue<p> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){ //water = 0 hoga in ans
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int N = q.size(); //curr level pe itne hai
            while(N--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto it: dir){
                    int i_ = i + it[0];
                    int j_ = j + it[1];

                    if(i_>=0 && i_<n && j_>=0 && j_<m && ans[i_][j_] ==-1 ){
                        ans[i_][j_] = ans[i][j] +1; 
                        q.push({i_,j_});
                    }
                }
            }
        }
        return ans;

    }
};