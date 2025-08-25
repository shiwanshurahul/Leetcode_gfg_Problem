class Solution {
public:
//498 same
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {  //nice ques
        //use map as it stores key in sorted order
        map<int, priority_queue<int,vector<int>, greater<int>> > mp;  //min heap
        //vector le skte -> sort then front, back operation hota queue jaisa

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push(mat[i][j]); //each i-j ke corrosponding priority_queue me push
            }
        }

        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = mp[i-j].top();    //mp[i-j].back(); mp[i-j].pop_back();
                mp[i-j].pop();
            }
        }
        return dp;


    }
    // 00 01 02 03   //i+j-> neeche se upar || i-j-> upar se neeche ka khel
    // 10 11 12 13
    // 20 21 22 23
};