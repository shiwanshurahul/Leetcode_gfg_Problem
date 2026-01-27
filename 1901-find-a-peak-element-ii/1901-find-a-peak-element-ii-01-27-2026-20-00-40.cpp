class Solution {
public:
int n = 0;
int m = 0;
bool is_valid(int i, int j){
    if(i>=n || i<0 || j>=m || j<0)
        return 0;
    return 1;    
} 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //brute force -> o(n*m)
        n = mat.size();
        m = mat[0].size();

        int i=0,j=0;
        while(i<n && j<m){
            int flag = 1; //1 rhega mtlab apne 4ron adjc se > hai
            if(is_valid(i+1,j) && mat[i][j] < mat[i+1][j]){
                i++;
                flag = 0;
            }
            else if(is_valid(i-1,j) && mat[i][j] < mat[i-1][j]){
                i--;
                flag = 0;
            }
            else if(is_valid(i,j+1) && mat[i][j] < mat[i][j+1]){
                j++;
                flag = 0;
            }
            else if(is_valid(i,j-1) && mat[i][j] < mat[i][j-1]){
                j--;
                flag = 0;
            }
            if(flag)  //flag = 1 rha
                return {i,j};  
        }
        return {-1,-1};

    } //T.C -> O(n+m)
};