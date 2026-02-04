class Solution {
public:
//express base case in i and j
// explore all possible case
//return min,max,sum, ..
int solve(int i, int j, vector<int>&nums){ //p1
    if(i>j)
        return 0; //add 0 to score

    int take_i = nums[i] + min(solve(i+2,j,nums), solve(i+1,j-1,nums));
    int take_j = nums[j] + min(solve(i+1,j-1,nums), solve(i,j-2,nums));

    return max(take_i, take_j);    //ur bes

}
    bool predictTheWinner(vector<int>& nums) {
        //similar to stone game 2
        //min-max game strateg
        //p1 ke respt me likh do and
        // expec wrst/min from p2 with do ur bst -> max
        //min(solve(i+2,j), solve(i+1,j-1))
        //ki wo v max chune
        int score_p1 = solve(0,nums.size()-1,nums);
        int sum = 0;
        for(auto it: nums){
            sum+= it;
        }
        int score_p2 = sum-score_p1;
        return score_p1 >= score_p2;

    }
};