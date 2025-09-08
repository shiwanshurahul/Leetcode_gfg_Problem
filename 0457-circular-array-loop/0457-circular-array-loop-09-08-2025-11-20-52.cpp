class Solution {
public: //check loop in array:

    bool circularArrayLoop(vector<int>& nums) {
        
        int n = nums.size();

        // int i = 0;
        // while(i<nums.size()){
        //     if( nums[i] != -1e9 ){
        //         if(nums[i]>=0 ){
        //             int k = nums[i];
        //             nums[i] = -1e9;   //mark visited
        //             i = (i+k)%n;
        //         }
        //         else{   //-ve no
        //             int k = nums[i];
        //             nums[i] = -1e9;   //mark visited
        //             i = i+k <0 ? n+i : i+k;
        //         }
        //     }
        //     else{
               
        //         return true;
        //     } 
        // }
        // return false;

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                continue;
            if(dfs(i,nums,n,vis))
                return 1;    
        }
        return false;
    }
    bool dfs(int curr, vector<int>&nums, int n, vector<int> &vis){
        int next = (curr + nums[curr]%n + n)%n;

        if(curr==next ) return false; //khud pe aaye = ye wala loop not allowed
        if(vis[next]==1)    //cycle hai
            return true;

        vis[curr] = 1;    //mark visited
        
        bool res = false;
        if( (nums[next]>0 && nums[curr]>0) || (nums[next]<0 && nums[curr]<0 ) )
            res |= dfs(next,nums,n,vis);

        nums[curr] = 0;
        vis[curr] = 0;   //or vis[curr] = 2,3 kr skte
        return res;         
    }
};