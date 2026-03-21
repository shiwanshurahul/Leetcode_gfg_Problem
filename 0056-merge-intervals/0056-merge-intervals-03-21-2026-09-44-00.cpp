class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //overlapp -> start[t] <= end[prev_t] 
        int n = intervals.size();
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];  //[1,3]
        int i=0;
        while(i<n){
            if(intervals[i][0]<=temp[1]){  //overlappin -> 1<3, 2<3
               temp[1] =max(intervals[i][1],temp[1]);
            }
            else{
               ans.push_back(temp); // store curr (1,6)
               temp=intervals[i];   // point to curr non overlappin
            }
            i++;
        }
       ans.push_back(temp);
       return ans;
    }
};