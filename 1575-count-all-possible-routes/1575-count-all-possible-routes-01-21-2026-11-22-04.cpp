class Solution {
public:
int dp[101][201];
int M = 1e9 + 7;
int solve(vector<int>& locations, int i,int finish,int fuel,int n){
    if(fuel<0)
        return 0;
    if(i>=n)
        return 0; 
    if(dp[i][fuel] !=-1)
        return dp[i][fuel];
    int ans = 0;     

    if(i == finish)
        ans+= 1;   //but aur explore kro

    for(int j=0;j<n;j++){   //loop se hi ja skte har jagah warna -1 kaise
        if(i !=j){  //i se i kyu jaoge
            ans = (ans%M + (solve(locations,j,finish,fuel - abs(locations[i]- locations[j]),n ))%M  )%M;
        }
    }
    return dp[i][fuel] = ans%M;         
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //nultiple time finnish pe ja skte
        //e.g. -> start ->finish -> start->finish v solutn hai
        //left an sright dono ja skte -> i-1,i+1
        int n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel,n);
    }
};