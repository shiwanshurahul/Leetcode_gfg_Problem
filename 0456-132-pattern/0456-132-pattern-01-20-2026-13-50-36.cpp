class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //b.f -> 0(n^3)
        //i<j<k -> arr[i]<arr[k]<arr[j]
        //e.g.arr=[1,3,2], i=0,j=1,k=2 -> 1<2<3 = 132
        // = k should be largest, j is 2nd large, i is smallest
        int n = nums.size();
        int j  = -1e9;  //second largest no wala (2)
        stack<int>st; //largest number store kro

        for(int i=n-1;i>=0;i--){
            if(nums[i]<j)
                return true;

            while(!st.empty() && st.top() < nums[i]){
                j = st.top();  //second largest toh ho skta na
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};