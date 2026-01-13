class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];  //[1,3]
        int i=0;
        while(i<n){
            if(intervals[i][0]<=temp[1]){  //overlappin -> 3>2
               temp[1] =max(intervals[i][1],temp[1]);
            }
            else{
               ans.push_back(temp); // store curr
               temp=intervals[i];   // point to this non overlappin
            }
            i++;
        }
       ans.push_back(temp);
       return ans;
    }
};