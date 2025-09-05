class Solution {
public:
long long solve(vector<vector<int>>& questions, int i, vector<long long>& dp){
    if(i>=questions.size())
        return 0;  //0 add krke return points

    if(dp[i] !=-1)
        return dp[i];

    long long pick = questions[i][0] + solve(questions, i+1+questions[i][1], dp);  //itne ke bad
    long long skip = solve(questions, i+1, dp);    //next pe

    return dp[i] = max(pick, skip);

}
    long long mostPoints(vector<vector<int>>& questions) {
        //max points questions[i][0]
        //explore all
        //1-d dp since 1 parametre is changing 
        vector<long long> dp(questions.size()+1, -1);
        return solve(questions,0, dp);
    }
};