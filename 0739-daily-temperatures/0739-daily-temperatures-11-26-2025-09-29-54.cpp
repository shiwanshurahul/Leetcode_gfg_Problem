class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // cnt of all elements until ngr 
        //different than no of visible people Input: [10, 6, 8, 5, 11, 9]
           stack<int> st;
     vector<int >ans;
        int n= temperatures.size();
     for(int i=n-1;i>=0;i--){

   while(!st.empty() && temperatures[i]>= temperatures[st.top()] ){
    st.pop();
  }
  if(st.empty()){ 
    ans.push_back(0);
    }
   else{   //st is not empty
     ans.push_back(st.top()-i);
   }
    st.push(i);
     }
     reverse(ans.begin(),ans.end());
     return ans;
    }
};