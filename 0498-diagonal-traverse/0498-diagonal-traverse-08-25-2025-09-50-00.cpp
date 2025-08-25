class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    
    int n = mat.size();
    int m = mat[0].size();
    map<int, vector<int>> mp;  //sorted me rkhta keys
    vector<int> ans;
  
    //fill the map
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i+j].push_back(mat[i][j]);  //each i+j wale ke vector me store
        }
    }

    int flag = 1;
    for(auto it: mp){
        if(flag)  
            reverse(it.second.begin(), it.second.end());

        for(auto it1: it.second){
            ans.push_back(it1);
        }
        flag = !flag;
    }
  
    return ans;
    }    // 00 01 02   ->each i+j pe store values in map
        //  10 11 12
        //  20 21 22

        //i.e 0 -> 1
        //    1 -> 2,4
        //    2 -> 7,5,3
        //    3 -> 8,6
        //    4 -> 9
    
};