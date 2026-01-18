
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            //sorted hai arr
            //3 cases -> overlapping = min,max lelo and newInterval ko update
            // newInterval < interval = aage aur greater values hi hoengi = break
            //e.g. newInterval = [1,5] and interval=[6,9]

            //newinterval > interval -> ye wala interval ans me as it is aaega
            //e.g. newInterval=[]
            int i=0;
            vector<vector<int>> ans;
            while(i<intervals.size()){
                if(intervals[i][1] < newInterval[0]){  //-> newinterval > interval 
                    ans.push_back(intervals[i]);
                }
                else if(intervals[i][0]> newInterval[1]){
                    break;  //aage aur bade hoga e.g. 9>5
                }
                else{  //overlapping-> interval[i][1] > newInterval[0]
                    newInterval[0] = min(newInterval[0],intervals[i][0]);
                    newInterval[1] = max(newInterval[1],intervals[i][1]);
                }  //newInterval = [1,5]
                i++; //har bar
            }
            ans.push_back(newInterval);
            while(i<intervals.size()){
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
    }
};








    //  int n =intervals.size();
    //     vector<vector<int>> ans;
    //    sort(intervals.begin(),intervals.end());
    //    vector<int> temp =intervals[0];
    //    int i=0;
    //    while(i<n){
    //        if(intervals[i][0]<=temp[1]){
    //            temp[1] =max(intervals[i][1],temp[1]);
    //        }
    //        else{
    //            ans.push_back(temp);
    //            temp=intervals[i];
    //        }
    //        i++;
    //    }
    //    ans.push_back(temp);
    //    return ans;