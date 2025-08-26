class Solution {
public:
static bool cmp(vector<int> & a, vector<int> & b){
    
        // return a[1] < b[1];  -> sirf ye likhega toh khali second digit ke basis pe sorting krega ascending me

        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];     
}
int solve(vector<vector<int>> &envelope, int i, int prev){
    if(i >= envelope.size())
        return 0;

    int take = 0;
    int skip = 0;

    if( prev == -1 || envelope[i][1] > envelope[prev][1] && envelope[i][0] > envelope[prev][0]){
        take = 1 + solve(envelope, i+1, i);
        skip = solve(envelope, i+1, prev);  //dp
    }
    else {
        skip = solve(envelope, i+1, prev);
    }   

    return max(take ,skip);

}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        //h1<h2 && w1 < w2
        sort(envelopes.begin(), envelopes.end(),cmp);
        // 1st digit ascending form me, second descending form me

        //ab height wale pe envelope[i][1] wale vector pe lis laga do
        // int lis_length = solve(envelopes,1,-1);  //length of lis

        //dp with b.s  -> Lis ->  //nlogn me kr skte -> lowerbound
        vector<int> ans;

        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size(); i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int idx = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();  //just increasing/same no
                ans[idx] = envelopes[i][1];
            }       
        }
        return ans.size();


        
      
    }
};
//   return a[0]==b[0] ?a[1]>b[1]:a[0]<b[0];