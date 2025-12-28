class Solution {
public:
int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
    if(i>= word1.length())
        return word2.length()-j;  //extra char = itne delete hoenge

    if(j>= word2.length())
        return word1.length()-i;   // itne delete hoenge

    if(dp[i][j] !=-1)
        return dp[i][j];

     int insert_ans = 0;
     int delet_ans = 0;
     int replace_ans = 0;

    if(word1[i] == word2[j]){
        return dp[i][j] = solve(i+1,j+1,word1,word2, dp);  //no operation kr rhe
    }
    else{   //1 operation kr rhe
        insert_ans =  1 + solve(i, j+1, word1, word2, dp);     //rhorse, ros -> i wahin hai j badha do
        delet_ans = 1 + solve(i+1, j, word1,word2, dp);       //i is deleted
        replace_ans = 1 + solve(i+1, j+1, word1, word2, dp);   //ith char ko jth char bana diya = dono ka next word compare
    }    

    return dp[i][j] = min(insert_ans, min(delet_ans, replace_ans));
}
    int minDistance(string word1, string word2) {
        //min operation including insert, delete and replace -> famous ques
        //multiple ways to convert hai but sbse min operation lage min(4,5,6,3) = 3
        
        //char match i == j -> call i+1, j+1 and no operation needed
        //!char match -> solution/ans find with insert -> j ke sath matched
        //            -> solution find with delete
        //            -> solution find with replace
        //   = teeno explore kr liya = min(insert_ans, delete_ans, replace_ans) 
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return solve(0,0,word1, word2, dp);
    }//insert kroge toh v return hoke uske bad delete and replace ka code check/execute hoga hi = dp
    //insert -> i se
};