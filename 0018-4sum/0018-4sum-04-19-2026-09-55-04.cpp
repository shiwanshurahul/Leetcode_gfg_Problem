class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //aleas 4ron me 1 unique hona chahiye
        //b.f -> o(n^4)
        // -> (logn)+(n^3)
        int n = nums.size(); 
        
        sort(nums.begin(),nums.end()); //[-2,-1,1,0,0,2]
        set<vector<int>> st; //store unique elem
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                int s =j+1,e =n-1;
                while(s<e){
                    if((long int)nums[i] +(long int)nums[j]+(long int)nums[s]+
      (long int)nums[e]==(long int)target){
                st.insert({nums[i],nums[j],nums[s],nums[e]});
                        s++;e--;
                    }
                    else if((long int) nums[i] + (long int)nums[j]+ (long int) nums[s]+ (long int)nums[e]>target){
                        e--;
                    }
                    else{
                        s++;
                    }                    
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }                  
        return ans;  
    }
};