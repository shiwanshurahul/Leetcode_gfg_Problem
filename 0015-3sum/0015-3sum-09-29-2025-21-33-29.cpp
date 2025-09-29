class Solution {
public:

//  {    1, 2, 3          }     
//  {  10, 20, 30, 40     }     
//  {   5, 15, 25, 35, ...}

//duplicate triplets se bachne ke liye atleast 1 value in it should be unique
    vector<vector<int>> threeSum(vector<int>& nums) {
        //n3 -> brute force
        //o(n^2)logn
        vector<vector<int>> ans;
        set<vector<int>> st; //to remove duplicates triplets
        int n =nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int s =i+1,e =n-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]==0){
                    st.insert({nums[i],nums[s],nums[e]});
                    s++;e--;
                }
                else if(nums[i]+nums[s]+nums[e]>0){  //e ko piche lao
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        for(auto it: st)  //it has unique triplets
            ans.push_back(it);
        return ans;   
    }
};