class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //b.f -> 0(n^3)
        //i<j<k -> arr[i]<arr[k]<arr[j]
        //e.g. arr=[1,3,2], i=0,j=1,k=2 (idx) -> 1<2<3 = 132
        // = k should be largest, j is 2nd large, i is smallest

        //index maintain krne ke liye piche se traverse kro
        //st me largest no store rkho isse bada aaye toh largest becomes second largest and jaise hi koi second largest se less ho toh return true

        int n = nums.size();
        int j = -1e9;  //second largest no wala (2)
        stack<int>st;  //largest number store kro

        for(int i=n-1;i>=0;i--){
            if(nums[i]<j)   //nums[i] is smallest. < j < st.top()
                return true;

            while(!st.empty() && st.top() < nums[i]){ //curr_elm(4) >st.top()(2)
                j = st.top();  //second largest (2)
                st.pop();
            }
            st.push(nums[i]);  //har bar 2; 4
        }
        return false;
    }
};