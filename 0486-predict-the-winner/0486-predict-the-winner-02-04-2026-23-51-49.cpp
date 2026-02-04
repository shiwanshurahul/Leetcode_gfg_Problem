class Solution {
public:
//express base case in i and j
// explore all possible case
//return min,max,sum, ..
int solve(int i, int j, vector<int>&nums){ //p1
    if(i>j)
        return 0; //add 0 to score of p1

    int take_i = nums[i] + min(solve(i+2,j,nums), solve(i+1,j-1,nums));
    int take_j = nums[j] + min(solve(i+1,j-1,nums), solve(i,j-2,nums));

    return max(take_i, take_j);    //ur bes

}
int solve1(int i,int j, vector<int>&nums){ //diff b/w score
    if(i>j)
        return 0;

    int take_i = nums[i] - solve1(i+1,j,nums);
    int take_j = nums[j] - solve1(i,j-1,nums);

    return max(take_i, take_j);    
}
    bool predictTheWinner(vector<int>& nums) {
        //similar to stone game 2
        //min-max game strateg
        //p1 ke respt me likh do and
        // expec wrst/min from p2 with do ur bst -> max
        //min(solve(i+2,j), solve(i+1,j-1))
        
        int n = nums.size();
        // int score_p1 = solve(0,n-1,nums);
        // int sum = 0;
        // for(auto it: nums){
        //     sum+= it;
        // }
        // int score_p2 = sum-score_p1;
        // return score_p1 >= score_p2;

        //m2:
            // score_p1 - score_p2 ke rspct me do >= 0
            //dono ke lie recursn ek sat 
            return solve1(0,n-1,nums) >= 0;
    }
};