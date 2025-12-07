class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // cnt of all elements until ngr -> st.top > arr[i]
        //different than no of visible people Input: [10, 6, 8, 5, 11, 9]
        stack<pair<int,int>> st;  //temp, day/i
        vector<int >ans;
        int n= temperatures.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>= st.top().first ){
                st.pop();
            }
            if(st.empty())
                ans.push_back(0);
            else     //st is not empty -> st.top() > temp[i]
                ans.push_back(st.top().second-i);
            
            st.push({temperatures[i], i});     
     }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};