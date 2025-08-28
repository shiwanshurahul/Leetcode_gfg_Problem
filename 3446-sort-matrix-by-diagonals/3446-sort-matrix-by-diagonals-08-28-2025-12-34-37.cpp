class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //bottom left diagonal including middle diagonal -> decreasing order
        //top-right triangle -> increasing order (0,1 0,2 1,2)  

        int n = grid.size();
        int m = grid[0].size();        
        unordered_map<int, vector<int> > mp; 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(grid[i][j]);   //har i-j pe vector me store uski corrosponding values
            }
        }

        vector<vector<int>> dp(n,vector<int>(m,0));

        //sort as per quest  -> seedha ek for loop me it.first>=0 ke basis pe v kr skte
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-j >=0)   //bottom left diagonal
                    sort(mp[i-j].begin(), mp[i-j].end()); //descending me req -> ascending ke last se iterate krenge 
                else
                    sort(mp[i-j].begin(), mp[i-j].end(), greater<int>());   
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                dp[i][j] = mp[i-j].back();  //vector hai
                mp[i-j].pop_back();
            }
        }

        return dp;




    } // 00 01 02
      // 10 11 12
      // 20 21 22
      
      //i+j
      //0 -> 1
      //1 ->7,9
      //2-> 3,8,4
      //3-> 2,5
      //4 -> 6
};//diagonally up -> i+j
    //diagonally down -> i-j