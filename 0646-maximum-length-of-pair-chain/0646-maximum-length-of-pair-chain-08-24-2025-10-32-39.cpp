class Solution {
public:
static bool cmp(vector<int> & a, vector<int> &b){
    return a[1] < b[1];  //ascending 
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);  //based on right

        int i =1;
        int j = 0;
        int cnt = 1;
        
        while(i<pairs.size()){
            if(pairs[i][0] > pairs[j][1]){
                cnt++;       
                j = i;
            }
            i++;    
        }
        return cnt;
    }
};