class Solution {
    private:
     int lcs(string word1, string word2,int m,int n) {
        int t[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]== word2[j-1])
                    t[i][j] = 1+ t[i-1][j-1];
                    else
                    t[i][j] = max(t[i][j-1], t[i-1][j]); 
            }
        }
         return t[m][n];
     }
public:
    int minDistance(string word1, string word2) {
           int m =word1.length();
        int n =word2.length();
        int l =lcs(word1,word2,m,n);
        return m +n-2*l;
    }
};