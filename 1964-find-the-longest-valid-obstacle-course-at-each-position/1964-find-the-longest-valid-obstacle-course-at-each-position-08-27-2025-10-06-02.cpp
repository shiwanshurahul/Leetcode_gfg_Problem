class Solution {
public:
int solve(vector<int> &obstacles, int i, int prev, int n){
    if(i >n)  //idx se jyada
        return 0;

    int skip = 0;
    int take = 0;

    if(prev == -1 || obstacles[i]>= obstacles[prev]){
        take = 1 + solve(obstacles,i+1,i,n);
        skip = solve(obstacles,i+1,prev,n);  //dp
    }
    else {
        skip = solve(obstacles,i+1,prev,n);
    }

    return max(take, skip);

}
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        //each index pe usse pehle ka lis/same nikal lo
        //problem -> us particular index ko include krna hai toh us index se 0th index tak decreasing dhundho
        int n = obstacles.size();

        vector<int> lis;  ///keep track of value 
        vector<int> ans(n,0);  //us value ka ans
        
        // for(int i=0;i<n;i++){
        //     ans.push_back(solve(obstacles,0,-1,i)); //i tak
        // }  //include krna hai us ind ko + tle.

        lis.push_back(obstacles[0]);
        ans[0] = 1; 
        int len = 1;

        for(int i=1;i<n;i++){
            if(obstacles[i] >= lis.back()){
                lis.push_back(obstacles[i]);
                len++;
                ans[i] = len;
            } 
            else{    
                int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
                lis[idx] = obstacles[i];
                ans[i] = idx+1; //len   
            }   
        }

        return ans;
    }
};//lower bound -> This means it finds the first element that is either
// equal to value or greater than value.

//upper bound -> It finds the first element strictly larger than value