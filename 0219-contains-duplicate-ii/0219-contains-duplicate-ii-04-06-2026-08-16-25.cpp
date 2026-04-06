class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i =0,j=0;
        int n =nums.size();
        unordered_set<int> st;
        //st me rkhlo bcz <=k tak me ho skta duplicate
        // = set me store only values b/w a window <k
        //third type -> j to i me legal rkho warna slide 
        while(j< n){
            while(abs(j-i) >k){     //slide the window
                st.erase(nums[i]);
                i++;
            }    // <=k me hai
            if(st.find(nums[j]) !=st.end())
                return true;
            else
                st.insert(nums[j]);
            j++;
        }
        return false;
    }
};