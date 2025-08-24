class Solution {
public:
 static bool comp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
       //   This sorting is done based on the ending values of the pairs in ascending order. 
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int len =1;
        sort(pairs.begin(),pairs.end(),comp);
        int i=1;
        int prev =0;
        while(i<pairs.size()){
           if(pairs[i][0]>pairs[prev][1]){
           len++;
           prev =i;
           }
           i++;
          // maxi =max(len,maxi);
        }
        return len;
    }
};