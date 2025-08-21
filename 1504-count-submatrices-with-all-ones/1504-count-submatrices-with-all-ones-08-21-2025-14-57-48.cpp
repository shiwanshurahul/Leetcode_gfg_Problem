class Solution {
public:
int solve(int i,int j, int n, int m, vector<vector<int>> &mat){
        if(i>= n || i<0 || j>= m || j<0)
            return 0;

        if(mat[i][j] == 0)
            return 0;

        int down = 1 + solve(i+1,j,n,m,mat);  //1 pe hai toh 1 toh hai hi
        int right = 1 + solve(i,j+1,n,m,mat); 
        // int diagonal = 1 + solve
        return  max(down,right);       
}
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 )   // 1 pe ans calc
                    ans += solve(i,j,n,m, mat);
            }
        }
        return ans;
    }
};