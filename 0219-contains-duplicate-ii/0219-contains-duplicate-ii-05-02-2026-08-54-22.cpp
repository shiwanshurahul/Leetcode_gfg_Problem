class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        //third type of slidin windo -> j to i me legal rkho warna slide
        //st me rkhlo bcz <=k tak me ho skta duplicate
        // = set me store only values b/w a window <k 
        int i =0,j=0;
        int n =nums.size();
        unordered_set<int> st;
       
        while(j<n){
            while(abs(j-i) >k){   //ilegal cas
                st.erase(nums[i]);   // remove calc for i
                i++;                 // slide the windo
            }    // <=k me ha
            if(st.find(nums[j]) !=st.end())
                return true;
            else
                st.insert(nums[j]);
            j++;     //har bar
        }
        return false;
    }
};