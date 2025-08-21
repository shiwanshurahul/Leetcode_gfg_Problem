class Solution {
public:
int solve(vector<int>&v){  //1-d me sare 1 ka cnt/i pe khatam hone wale sare 1 ka cnt
    int cnt=0;
    int ans=0;
    for(int i=0;i<v.size();i++){
        if(v[i]== 1)
            cnt++;
        else
            cnt =0;
        ans += cnt;        //harbar 1,3,6
    }
    return ans;
}
    int numSubmat(vector<vector<int>>& mat) {
        // ans +=cnt since all submatrices -> 2348
        //1-d me toh nikal skte = ans+=cnt //idhar 2-d me hai
        //2-d ke liye v same hi hai -> convert to 1-d how?
        //if same row me sare col 1 hai toh 1 warna 0 and fir iska ans nikal lo
        //e.g. 1   1
        //     1   0
        //     1   1
   // & lelo = 1 0 -> is 1-d ka nikal lo all submatrices
        int n =mat.size();
        int m = mat[0].size();

        int ans=0;

        for(int start_row=0;start_row<n;start_row++){
             vector<int> v(m,1);  
             for(int end_row=start_row;end_row<n;end_row++){
                for(int col=0;col<m;col++){   //v ke liye
                    v[col] = v[col] & mat[end_row][col]; // 1 & 1 & 0 = 0 aaega
                }
                ans +=solve(v);
            }
        }
        return ans;
    }
};