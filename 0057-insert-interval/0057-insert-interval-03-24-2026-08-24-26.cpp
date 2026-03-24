
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            //sorted hai arr
            //3 cases -> overlapping = min,max lelo and newInterval ko update
            // i.e interval[i][1] >= newInterval[0]
            //  interval > newInterval = aage aur greater values hi hoengi = break
            //e.g. newInterval = [1,5] and interval=[6,9]

            //newinterval > interval -> cur interval ans me as it is aega
            //e.g. newInterval=[6,9] and interval = [1,5]
            int i=0;
            vector<vector<int>> ans;

            while(i<intervals.size()){
                if(intervals[i][1] < newInterval[0]){  //-> newinterval > interval 
                    ans.push_back(intervals[i]);  //cur as it is rhega
                }
                else if(intervals[i][0]> newInterval[1]){ //interval is > newInterva
                    break;  //aage aur bade hoga e.g. 9>5
                }
                else{ //overlapping-> interval[i][1] >= newInterval[0] e.g. [3,5] > [4,8]
                    newInterval[0] = min(newInterval[0],intervals[i][0]);
                    newInterval[1] = max(newInterval[1],intervals[i][1]);
                }  //newInterval = [1,5] ; [3,8], [3,8], [3,10]
                i++; //har bar
            } //while loop ende
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