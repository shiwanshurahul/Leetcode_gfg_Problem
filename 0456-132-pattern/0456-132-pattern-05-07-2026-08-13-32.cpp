class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //b.f -> 0(n^3)
        //i<j<k && arr[i]<arr[k]<arr[j]  i.e arr[j]>arr[i] && arr[j]>arr[k]
        //e.g. arr=[1,3,2], i=0,j=1,k=2 (idx) -> 1<2<3 = 132
        // = jth elem should be largest, k is 2nd large, i is smallest

        //idx maintai krne k liye piche se travers kr
        //st me larges no store rkho isse bada aye toh larges becomes
        //2nd larges and jaise hi koi 2nd largest se less ho toh retur true

        //ngr jais -> st me larges elem rkh -> st.top() > arr[i] rkhne ki kosi
        int n = nums.size();
        int k = -1e9;  //second larges no wala (2)
        stack<int>st;  //larges number store kro

        for(int i=n-1;i>=0;i--){
            if(nums[i]<k)   //nums[i] is smalest < k < st.top()
                return true;

            while(!st.empty() && st.top() <nums[i]){ //curr_elm(4) >st.top()(2)
                k = st.top();  // 2nd larges = 2; 
                st.pop();      // st m curr = larges stor kro
            }
            st.push(nums[i]);  //har br 2; 4; 
        }
        return false;
    }
};